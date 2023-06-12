#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#define ARR_LENGTH (0x7FFF * 2)
#define SEARCH_CONST (ARR_LENGTH / 2)

int main(){
    time_t t = time(NULL);
    srand(t);
    int arr_sorted[ARR_LENGTH];
    int arr_not_sorted[ARR_LENGTH];
    struct timeval stop, start;
    
    // Fill arr
    for (int i = 0; i < ARR_LENGTH; i++){
        arr_sorted[i] = i;
        arr_not_sorted[i] = rand();
    }


    // Sorted list
    int enters = 0;
    gettimeofday(&start, NULL);
    for (int i = 0; i < ARR_LENGTH; i++){
        if (arr_sorted[i] < SEARCH_CONST)
            enters++;
    }
    gettimeofday(&stop, NULL);
    printf("Search in sorted arr %lu us\nEnters: %d\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec, enters); 
    
    // Not sorted
    enters = 0;
    gettimeofday(&start, NULL);
    for (int i = 0; i < ARR_LENGTH; i++){
        if (arr_not_sorted[i] < SEARCH_CONST)
            enters++;
    }
    gettimeofday(&stop, NULL);
    printf("Search in not sorted arr %lu us\nEnters: %d\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec, enters); 
    

    return 0;
}