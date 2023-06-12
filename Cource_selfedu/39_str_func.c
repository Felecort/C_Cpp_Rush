#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void){
    double width = 2.4, height = 3.4, depth = 1.2;
    char name[] = "Sofa";
    const size_t size = strlen(name) + 100;
    // char info[size];
    char *info = malloc(size);
    const char format[] = "W x H x D: (%.2f x %.2f x %.2f)";
    sprintf(info, format, width, height, depth);
    puts(info);
    free(info);

    double var_i = -1.23;
    char str_var[10];
    sprintf(str_var, "%.10f", var_i);
    puts(str_var); // Is string

    return EXIT_SUCCESS;
}