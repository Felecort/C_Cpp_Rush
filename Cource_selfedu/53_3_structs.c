#include <stdio.h>
#include <stdlib.h>


struct tag_point {
    double x, y, z;
};

int main(void)
{
    int max_points = 3;
    struct tag_point figure[max_points];
    int fugure_points = 2;
    figure[0].x = 1.2;
    figure[0].y = 1.5;
    figure[0].z = 1.789;

    figure[1].x = 15.2;
    figure[1].y = 15.5;
    figure[1].z = 17.7689;


    return EXIT_SUCCESS;
}