#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int matrix_sum(size_t rows, size_t cols, int m[rows][cols]){
    int total = 0;
    for(size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < cols; c++)
            total += m[r][c];
    return total;
}

int main(void){
    time_t t = time(NULL);
    srand(t);
    int rows = rand() % 10 + 2;
    int cols = rand() % 10 + 2;
    int array[rows][cols];
    int value;
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            value = rand() % 10;
            array[r][c] = value;
            printf("%d ", value);
        }
        printf("\n");
    }
    int total = matrix_sum(rows, cols, array);
    printf("%d \n", total);
    

    return EXIT_SUCCESS;
}