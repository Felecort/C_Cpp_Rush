#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>
#include <assert.h>

int main(void)
{
    int arr[9];
    _Static_assert(_Alignof(arr) == 4, "Unexpected alignment");
    printf("Alignment of arr = %zu \n", _Alignof(arr));
    printf("Alignment of max_align_t = %zu \n", alignof(max_align_t));
    assert(alignof(max_align_t) == 16);

    return EXIT_SUCCESS;
}