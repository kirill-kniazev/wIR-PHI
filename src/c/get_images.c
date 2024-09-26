#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "include/PDCLIB.h"
#include <time.h>

__declspec(dllexport) void returnFinalImage(
    int image[], // final image to be return to python
    unsigned int width, // image width
    unsigned int height, // image height
    const unsigned int num_of_images, // must be even
    const unsigned int start_image, // to change start image, must be even
    unsigned long nDeviceNo)
{   
    // init some variables
    time_t stop, start; // for time measurment
    unsigned long nChildNo = 1; // always 1 in our case
    unsigned int image_len = width * height;
    unsigned long nRet;
    PDC_FRAME_INFO FrameInfo; // frame information structure
    unsigned long nErrorCode;

    // loop vars (to be used in parallel blocks)
    int i, j;

    // allocate memory for images
    unsigned short** data = (unsigned short**) malloc(sizeof(unsigned short*) * num_of_images);
        for (i = 0; i < num_of_images; ++i)
            data[i] = (unsigned short*) malloc(sizeof(unsigned short) * image_len);

    // retrieve frame information
    nRet = PDC_GetMemFrameInfo(
        nDeviceNo,
        nChildNo,
        &FrameInfo,
        &nErrorCode);

    if (nRet == PDC_FAILED) 
    {
        printf("PDC_GetMemFrameInfo Error %d\n", nErrorCode);

        // free allocated memory
        for (i = 0; i < num_of_images; ++i)
            free(data[i]);
        free(data);

        return;
    }

    // enable of Burst Transfer Function
    // this should speed up retrieving process
    nRet = PDC_SetBurstTransfer(nDeviceNo,
                                PDC_FUNCTION_ON,
                                &nErrorCode);

    if (nRet == PDC_FAILED) {
        printf("PDC_SetBurstTransfer Error %d\n", nErrorCode);

        // free allocated memory
        for (i = 0; i < num_of_images; ++i)
            free(data[i]);
        free(data);

        return;
    }

    // check for proper image number
    if (num_of_images + start_image > FrameInfo.m_nRecordedFrames)
    {
        printf(
            "Number of available images (%d) is less then demanded (%d)!",   
            FrameInfo.m_nRecordedFrames,      
            num_of_images);

        // free allocated memory
        for (i = 0; i < num_of_images; ++i)
            free(data[i]);
        free(data);

        return;
    }

    // skip first `start_image` images because they could be bad
    start = time(NULL); // for time checking
    for (i = 0; i < num_of_images; ++i)
    {
        // retrieve image
        nRet = PDC_GetMemImageData(
            nDeviceNo,
            nChildNo,
            i + start_image,
            16,
            data[i],
            &nErrorCode);

        if (nRet == PDC_FAILED) {
            printf("PDC_GetMemImageData Error %d\n", nErrorCode);

            // free allocated memory
            for (int i = 0; i < num_of_images; ++i)
                free(data[i]);
            free(data);
            
            return;
        }
    }
    stop = time(NULL);
    printf("Retrieving %d images took %ld sec\n", num_of_images, stop - start);
    // now we should have even number of images in our `data` array
    // subtract "cold" (odd) images from "hot" (even)

    // allocate memory for `hotMinusCold` array
    printf("Processing raw data to image... ");
    start = time(NULL);
    int** hotMinusCold = (int**) malloc(sizeof(int*) * num_of_images / 2);
        for (i = 0; i < num_of_images / 2; ++i)
            hotMinusCold[i] = (int*) malloc(sizeof(int) * image_len);

    for (i = 0; i < num_of_images; i += 2)
    {
        for (j = 0; j < image_len; ++j)
            hotMinusCold[i / 2][j] = data[i][j] - data[i + 1][j];
    }

    // we don't need `data` array any more
    for (i = 0; i < num_of_images; ++i)
        free(data[i]);
    free(data);

    // let's summurize all images in `hotMinusCold` array
    int sum; // init sum variable

    for (i = 0; i < image_len; ++i)
    {
        sum = 0;
        for (j = 0; j < num_of_images / 2; ++j)
            sum += hotMinusCold[j][i];
        image[i] = sum;
    }
    stop = time(NULL);
    printf("Done!. It took %d sec.\n\n", stop - start);
    
    // we don't need `hotMinusCold` array any more
    for (i = 0; i < num_of_images / 2; ++i)
        free(hotMinusCold[i]);
    free(hotMinusCold);
}