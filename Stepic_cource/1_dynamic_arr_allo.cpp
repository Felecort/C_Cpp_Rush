#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// God approach
int ** create_2d_array(size_t a, size_t b)
{
    int ** arr = new int * [a];
    arr[0] = new int [a * b];
    for (size_t i = 1; i < a; i++){
        arr[i] = arr[i - 1] + b;
    }
    return arr;
}

void delete_2d_arr(int ** arr, size_t a)
{
    delete [] arr[0];
    delete [] arr;
    arr = nullptr;
}

// Bad approach
int ** create_2d_arr_bad(size_t a, size_t b)
{
    int **arr = new int * [a];
    for (size_t i = 0; i < a; i++){
        arr[i] = new int[b]; 
    }
    return arr;
}
void delete_2d_array_bad(int **arr, size_t a)
{
    for (size_t i = 0; i < a; i++){
        delete [] arr[i];
    }
    delete [] arr;
    arr = nullptr;
}

int main(void)
{
    int ** arr = create_2d_array(3, 2);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            arr[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int stack_arr[2][3] = {{1, 2, 3}, {3, 4, 5}};
    cout << "ptr?: " << stack_arr[0] << " val: " << stack_arr[0][0] << endl;

    return 0;
}