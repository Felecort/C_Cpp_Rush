#include <stdio.h>


int main(){
    // m is pointer for 0 index (1st element)
    int m[20];
    printf("array size: %d\n", sizeof m);
    printf("%d, %p\n", m, m);
    m[7] = 13;
    printf("%d, %d, %d\n", m[7], *(m + 7), 7[m]);
    
    // Array is memory cell
    int x = 10;
    int *ptr_x = &x;
    printf("%d\n", ptr_x[0]);
    
    // Array of pointers
    int *ptr_arr[20];
    int a;
    a = 27;
    ptr_arr[5] = &a;
    printf("%p, %d\n", ptr_arr[5], ptr_arr[5][0]);

    // Initial valies for array
    int arr1[10] = {2, 3, 5, 7, 11, 13, 17, 19, 21, 23};
    int arr2[] = {1, 2, 3, 4};
    printf("arr1 size: %d, arr2 size: %d\n", sizeof(arr1), sizeof(arr2));
    int len_arr1 = sizeof(arr1) / sizeof(*arr1);
    int len_arr2 = sizeof(arr2) / sizeof(*arr2);
    printf("arr1 length: %d, arr2 length: %d", len_arr1, len_arr2);
}