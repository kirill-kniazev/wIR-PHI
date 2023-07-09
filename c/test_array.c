#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ARR_LEN 10000
#define DATA_LEN 512 * 512

void get_image(int* , int);

void return_array(int data[ARR_LEN][DATA_LEN]) {
	printf("In return_array\n");
	for (int i = 0; i < ARR_LEN; i++) {
		get_image(data[i], DATA_LEN);
	}
}

void return_array2(int* data, int arr_len, int data_len){
	for (int i = 0; i < arr_len; i++) {
		get_image(&data[i * data_len], data_len);
	}
}

void get_image(int* image, int len) {
	for (int i = 0; i < len; i++) {
		image[i] = i;
	}
}