#include <stdio.h>
#include <stdlib.h>

// Type belowed.
struct point_coords{
    char x;
    int y;
    int z;
};

int main(void)
{   
    struct point_coords pt;
    size_t size_pt = sizeof(pt);
    // Not 9, because alingment used
    printf("%d \n", size_pt);

    struct point_coords pt2 = {.y = 1, .z = 45};
    printf("x = %d, y = %d, z = %d \n", pt2.x, pt2.y, pt2.z);
    return EXIT_SUCCESS;
}

