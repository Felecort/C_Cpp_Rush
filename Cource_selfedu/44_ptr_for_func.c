#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int sq_rect(int width, int height)
{
    return width * height;
}


int main(void)
{

    int (*ptr_sq_rect) (int, int);
    printf("%p, %d\n", sq_rect, sq_rect);

    ptr_sq_rect = sq_rect;
    printf("%d\n", ptr_sq_rect(3, 4));
    return EXIT_SUCCESS;
}