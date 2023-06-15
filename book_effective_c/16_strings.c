#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <uchar.h>

int main(void)
{
    
    char ch = 'a';
    wchar_t wch = 'x';
    printf("size char = %d, size wchar-t = %d", sizeof(ch), sizeof(wch));
    return EXIT_SUCCESS;
}