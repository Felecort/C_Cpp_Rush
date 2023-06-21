#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

#define COLS 3
#define ROWS 5


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

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    // int ** first_row = m;
    unsigned row_with_min = 0;
    int * tmp;
    int min_value = INT32_MAX;

    for (unsigned row = 0; row < rows; row++){
        for (unsigned col = 0; col < cols; col++){
            if (m[row][col] < min_value){
                min_value = m[row][col];
                row_with_min = row;
            }
        }
    }
    cout << "Min val: " << min_value << ". row: " << row_with_min << endl;
    if (row_with_min != 0){
        tmp = m[0];
        m[0] = m[row_with_min];
        m[row_with_min] = tmp;

    }
}

int main(void)
{

    int **arr = create_2d_arr(ROWS, COLS);
    fill_2d_array(arr, ROWS, COLS);
    print_2d_array(arr, ROWS, COLS);
    swap_min(arr, ROWS, COLS);
    print_2d_array(arr, ROWS, COLS);
    
    return 0;
}