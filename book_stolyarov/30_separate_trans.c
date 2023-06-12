#include <stdio.h>

void print_arr(const char *arr, int length);


int main(){
    char message[] = "hello from module!";
    print_arr(message, 19);

    return 0;
}