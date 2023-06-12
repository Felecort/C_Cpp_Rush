#include <stdio.h>

/* 
    ALL THREE FUNCTIONS HAVE THE SAME PROFILE:
    return type and args type 
*/
double dbl_sum(const double *a, int size)
{
    return size > 0 ? *a + dbl_sum(a + 1, size - 1) : 0;
}

double dbl_min(const double *a, int size)
{
    double d;
    if (size == 1)
        return *a;
    d = dbl_min(a + 1, size - 1);
    return *a < d ? *a : d;
}

double dbl_average(const double *a, int size)
{
    return dbl_sum(a, size) / (double)size;
}

int main()
{
    // Poiter for all these three function
    double (*fptr1)(const double *, int);
    double (*fptr2)(const double *, int);
    // All samples correct
    fptr1 = dbl_min;
    fptr2 = &dbl_min;

    double arr[100];
    double res;
    // **f, ****f, &f, & & &f... - are the same
    res = (*fptr1)(arr, sizeof(arr) / sizeof(*arr));
    res = fptr(arr, sizeof(arr) / sizeof(*arr));
    return 0;
}