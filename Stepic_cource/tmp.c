/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct node{
    int counter;
    int value;
} node;

int* topKFrequent(int* nums, int num_elements, int k, int* returnSize){
    size_t node_size = sizeof(node);
    int filled_nodes = 0;
    int element;
    node *struct_array = malloc(num_elements * node_size);

    struct_array[0].value = nums[0];
    struct_array[0].counter++;
    filled_nodes++;
    printf("Start filling \n");
    for (int i = 1; i < num_elements; i++){
        element = nums[i];
        for (int node_idx = 0; node_idx < filled_nodes; node_idx++){
            if (struct_array[node_idx].value == element){
                struct_array[node_idx].counter++;
                break;
            }
            struct_array[node_idx].value = element;
            struct_array[node_idx].counter = 1;
            filled_nodes++;
        }
    }
    printf("Stop filling \n");

    for (int i = 0; i < filled_nodes; i++){
        printf("Value: %d Counter: %d \n", struct_array[i].value, struct_array[i].counter);
    }
}

int main(void)
{
    int arr[] = {1, 1, 1, 2, 2, 3};
    int num_elements = 6;
    int k = 2;
    int *returnSize;
    int *out = topKFrequent(arr, num_elements, k, returnSize);

    return EXIT_SUCCESS;
}