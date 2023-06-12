#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N   5


void show_field(const char (*f)[N])
{
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            printf("%c ", (f[i][j] == 0 ? '#' : '0'));
        putchar('\n');
    }
}


void open_zeros(const char (*f)[N], char (*sf)[N], int i, int j)
{
    if (f[i][j] != 0 || sf[i][j] == 1)
        return;
    sf[i][j] = 1;
    if (i - 1 >= 0 && f[i - 1][j] == 0) open_zeros(f, sf, i - 1, j);
    if (i + 1 <= N && f[i + 1][j] == 0) open_zeros(f, sf, i + 1, j);
    if (j - 1 >= 0 && f[i][j - 1] == 0) open_zeros(f, sf, i, j - 1);
    if (j + 1 <= N && f[i][j + 1] == 0) open_zeros(f, sf, i, j + 1);
}


int main(void)
{
    char field[N][N] = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
    };

    char support_field[N][N] = {0};
    show_field(support_field);
    printf("------------------\n");
    open_zeros(field, support_field, 2, 2);
    show_field(support_field);

    printf("------------------\n");
    open_zeros(field, support_field, 0, 3);
    show_field(support_field);

    return EXIT_SUCCESS;
}