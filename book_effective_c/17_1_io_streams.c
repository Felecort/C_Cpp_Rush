#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE my_stdout = *stdout;
    if (fputs("hello\n", &my_stdout) == EOF){
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}