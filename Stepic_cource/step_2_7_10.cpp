#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define COLS 3
#define ROWS 3

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int **startPoint = m;

}

int ** create_2d_array(size_t a, size_t b)
{
    int ** arr = new int * [a];
    arr[0] = new int [a * b];
    for (size_t i = 1; i < a; i++){
        arr[i] = arr[i - 1] + b;
    }
    return arr;
}

int main(void)
{
    int arr[ROWS][COLS] = {{1, 1, 10}, {2, 2, 2}, {3, 3, 3}};


    swap_min(arr, 3, 3);
    
    return 0;
}