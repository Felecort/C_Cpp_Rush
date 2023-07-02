#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

#define COLS 5000000
#define ROWS 10
#define ITERATIONS 10000

int **create_2d_arr(unsigned rows, unsigned cols)
{
    int **arr = new int *[ROWS];
    for (int i = 0; i < ROWS; i++){
        arr[i] = new int[COLS];
    }
    return arr;
}

void fill_2d_array(int **arr, unsigned rows, unsigned cols)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            arr[i][j] = std::rand() % 20 - 10;;
        }
    }
}

void print_2d_array(int **arr, unsigned rows, unsigned cols)
{
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << arr[i][j]  << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void delete_2d_array(int **m, int rows)
{
    for (int row = 0; row < rows; row++){
        delete [] m[row];
    }
    delete [] m;
}

int main(void)
{
    int **arr;
    for (unsigned iter = 0; iter < ITERATIONS; iter++){
        if ((iter % 100) == 0) cout << "Iteration: " << iter << endl;
        arr = create_2d_arr(ROWS, COLS);
        delete_2d_array(arr, ROWS);
    }
    cout << "finish" << endl;
    return 0;
}