/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define DEBUG

typedef struct node{
    char counter;
    int value;
} node;

int compare(struct node *arg1, struct node *arg2){
    if (arg1->counter > arg2->counter){
        return 0;
    }
    return 1;
}

int* topKFrequent(int* nums, int num_elements, int k, int* return_size){
    size_t node_size = sizeof(node);
    int filled_nodes = 0;
    int element;

    if (num_elements == 1){
        int *max_values = malloc(sizeof(int));
        max_values[0] = nums[0];
        *return_size = 1;
        return max_values;
    }

    node *struct_array = (node *)malloc(num_elements * node_size);

    struct_array[0].value = nums[0];
    struct_array[0].counter = 1;
    filled_nodes++;
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
#ifdef DEBUG
    for (int i = 0; i < filled_nodes; i++){
        printf("Value: %d Counter: %d \n", struct_array[i].value, struct_array[i].counter);
    }
    puts("---------------------------------");
#endif

    if (filled_nodes == 1){
        int *max_values = malloc(sizeof(int)); 
        max_values[0] = struct_array[0].value;
        *return_size = k;
        return max_values;
    }

    qsort(struct_array, filled_nodes, node_size, compare);

#ifdef DEBUG
    for (int i = 0; i < filled_nodes; i++){
        printf("Value: %d Counter: %d \n", struct_array[i].value, struct_array[i].counter);
    }
    puts("---------------------------------");
#endif
    int *max_values = malloc(k * sizeof(int)); 
    for(int i = 0; i < k; i++){
        max_values[i] = struct_array[i].value;
    }
    *return_size = k;
    return max_values;

}

int main(void)
{
    int arr[] = {4, 1, -1, 2, -1, 2, 3};
    int num_elements = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int return_size = 0;
    int *out = topKFrequent(arr, num_elements, k, &return_size);

    printf("Size: %d \n", return_size);
    for(int i = 0; i < return_size; i++){
        printf("%d ", out[i]);
    }

    return EXIT_SUCCESS;
}