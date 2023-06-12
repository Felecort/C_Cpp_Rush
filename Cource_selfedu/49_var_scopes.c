#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{

    int a = 6;
    int b = -3;
    int t = a + b;
    {
        int t = a; // New "t" int the new scope
        a = b;
        b = t;
        printf("inner t = %d \n", t); // Inner t
    }
    printf("%d \n", t); // Outer t
    puts("--------------------");

    while(t-- > 0){ // Old "t"
        int t = 10; // New "t"
        t--;
        printf("inner t = %d \n", t);
    }
    puts("--------------------");

    t = 10;
    for(int t = 0; t < 3; t++){
        printf("inner t = %d \n", t);
    }
    printf("main t = %d \n", t);

    return EXIT_SUCCESS;
}