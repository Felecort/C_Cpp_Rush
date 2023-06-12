#include <stdio.h>



int main(){
    char c_char = 'a';
    int c_int = 97;
    int a_b = ' ' + 'b';
    printf("char c: %c\nchar int: %c\n a and b: %c\n", c_char, c_int, a_b);
    
    char var_char = 33;
    int var_int = 33;
    long var_long = 33;
    long long var_l_long = 33;
    float var_float = 1.2;
    double var_double = 3.3;
    long double var_l_double = 3.3;

    printf("char: %d\n"
    "int: %d\n"
    "long %d\n"
    "long long %d\n"
    "float: %d\n"
    "double %d\n"
    "long double %d\n",
    sizeof(var_char), sizeof(var_int), sizeof(var_long), sizeof(var_l_long), sizeof(var_float), sizeof(var_double), sizeof(var_l_double));
    return 0;
}