#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(){

    int *image;
    unsigned int width = 200;
    unsigned int height = 200;
    int image_len = width * height;
    const unsigned int num_of_images = 100; // must be even

    // loop vars
    int i, j;

    // allocate memory for images
    unsigned short** data = (unsigned short**) malloc(sizeof(unsigned short*) * num_of_images);
        for (i = 0; i < num_of_images; ++i)
            data[i] = (unsigned short*) malloc(sizeof(unsigned short) * image_len);

    // allocate memory for `hotMinusCold` array
    int** hotMinusCold = (int**) malloc(sizeof(int*) * num_of_images / 2);
        for (i = 0; i < num_of_images / 2; ++i)
            hotMinusCold[i] = (int*) malloc(sizeof(int) * image_len);

    
    for (i = 0; i < num_of_images; ++i)
    {
        for (j = 0, j < image_len, ++j)
        {
            data[i][j] = i + j; 
        }
    }

    #pragma omp parallel for shared(data, hotMinusCold) private(i)
    for (i = 0; i < num_of_images; i += 2)
    {
        for (j = 0; j < image_len; ++j)
            hotMinusCold[i / 2][j] = data[i][j] - data[i + 1][j];
    }



    return 0;
}