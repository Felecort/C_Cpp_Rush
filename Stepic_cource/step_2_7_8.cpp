#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int ** create_2d_array(size_t a, size_t b)
{
    int ** arr = new int * [a];
    arr[0] = new int [a * b];
    for (size_t i = 1; i < a; i++){
        arr[i] = arr[i - 1] + b;
    }
    return arr;
}

int ** transpose(int ** matrix, unsigned rows, unsigned cols)
{
    int ** transposed_matrix = create_2d_array(cols, rows);
    for (unsigned col = 0; col < cols; col++){
        for(unsigned row = 0; row < rows; row++){
            transposed_matrix[col][row] = matrix[row][col];
        }
    }
    return transposed_matrix;
}



int main(void)
{
    int rows = 3;
    int cols = 5;
    // int matrix[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int ** matrix = create_2d_array(rows, cols);


    for (int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            matrix[row][col] = (row) * cols + col;
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;

    int ** transposed_matrix = transpose(matrix, rows, cols);

    for (int row = 0; row < cols; row++){
        for(int col = 0; col < rows; col++){
            // transposed_matrix[row][col] = row * col + row;
            cout << transposed_matrix[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}