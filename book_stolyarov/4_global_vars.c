#include <stdio.h>


int global_dangerous_variable_do_not_use_it;
int zeros_var;


int main(){
    global_dangerous_variable_do_not_use_it = 10;

    int random_data;
    printf("Global var: %d\n", global_dangerous_variable_do_not_use_it);
    printf("Global definited var: %d\n", zeros_var);
    printf("local definited var: %d\n", zeros_var);
    return 0;
}