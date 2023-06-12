#include <stdio.h>


int main()
{
    // Pointer for array. Not poiter for first element
    int matrix[3][4] = {{0, 0, 0, 0},
                        {0, 1, 2, 3},
                        {0, 2, 4, 6}};
    // int matrix[3][4];
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 4; j++)
    //         matrix[i][j] = i * j;
    int (*p)[4] = matrix;
  
    return 0;
}