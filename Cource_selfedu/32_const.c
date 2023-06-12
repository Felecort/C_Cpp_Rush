#include <stdio.h>

int main()
{

    short arr[] = {4, 5, 6, 3, 1};
    // Can change ptr, but not array data
    const short *ptr_ar;
    // Can change arr data, but not ptr
    short const *ptr_arr2;
    // No data, no ptr changes
    const short const *ptr_arr3;

    ptr_ar = arr;
    short x = ptr_ar[2];

    int matrix[3][3] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", *(*(matrix + i) + j));
            }
        printf("\n");
    }

    return 0;
}