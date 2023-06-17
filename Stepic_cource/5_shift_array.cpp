#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap_elements(int arr[], int idx)
{
    int tmp = arr[idx];
    arr[idx] = arr[idx + 1];
    arr[idx + 1] = tmp;
}


void rotate(int arr[], unsigned size, int shift)
{
    shift %= size;
    for (int i = 0; i < shift; i++){
        for (unsigned j = 0; j < (size - 1); j++){
            swap_elements(arr, j);
        }
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int shift = 6;

    rotate(arr, size, shift);

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}