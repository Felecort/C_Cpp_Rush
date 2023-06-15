#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum colours {red, green, blue};

void what_colour(int id){
    switch (id)
    {
    case red:
        printf("Red");
        break;
    case green:
        printf("Green");
        break;
    case blue:
        printf("Blue");
        break;
    default:
        printf("Undefined");
        break;
    }
}


int main(void)
{
    time_t t = time(NULL);
    srand(t);
    int colour_id = rand() % 3;
    what_colour(colour_id);

    return EXIT_SUCCESS;
}