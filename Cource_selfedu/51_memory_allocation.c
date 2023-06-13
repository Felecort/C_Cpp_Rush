#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BASIC_CAPACITY 10

void * append(short* data, size_t* length, size_t* capacity, short value){
    if (*length >= *capacity){
        *capacity *= 2;
        short *arr = malloc(sizeof(short) * (*capacity));
        if (arr == NULL){
            puts("Error!");
            return data;
        }
        for (int i = 0; i < *length; ++i)
            arr[i] = data[i];
        free(data);
        data = arr;
        puts("expanded");
    }
    data[*length] = value;
    (*length)++;
    return data;
}

int main(void){
    short *ptr_short = malloc(7 * sizeof(short));
    free(ptr_short);

    size_t capacity = BASIC_CAPACITY;
    size_t length = 0;
    short *data = malloc(sizeof(short) * capacity);
    for (int i = 0; i < 29; ++i)
        data = append(data, &length, &capacity, i);
    free(data);
    return EXIT_SUCCESS;
}