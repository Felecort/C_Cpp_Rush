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
    struct_array[0].counter = 1;
    filled_nodes++;
    printf("Start filling \n");
    for (int i = 1; i < num_elements; i++){
        element = nums[i];
        for (int node_idx = 0; node_idx < filled_nodes; node_idx++){
            if (struct_array[node_idx].value == element){
                struct_array[node_idx].counter++;
                break;
            }
            if ((filled_nodes - 1) == node_idx){
                struct_array[filled_nodes].value = element;
                struct_array[filled_nodes].counter = 1;
                filled_nodes++;
                break;
            }
        }
    }
    printf("Stop filling \n");

    for (int i = 0; i < filled_nodes; i++){
        printf("Value: %d Counter: %d \n", struct_array[i].value, struct_array[i].counter);
    }
}

int main(void)
{
    int arr[] = {1, 1, 2, 3, 3, 4, 1, 12, 3, 4, 5, 4, 1, 2, 5};
    int num_elements = sizeof(arr) / sizeof(arr[0]);
    printf("size arr: %d \n", num_elements);
    int k = 2;
    int *returnSize;
    int *out = topKFrequent(arr, num_elements, k, returnSize);

    return EXIT_SUCCESS;
}