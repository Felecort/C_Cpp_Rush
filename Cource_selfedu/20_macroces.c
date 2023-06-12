#include <stdio.h>

#define PRINT_2(A, B) printf("%d, %d\n", (A), (B))
#define SQ_PR(A, B) ((A) * (B))
#define TEXT(A, B) "square of rectangle (" #A ") x (" #B ")\n"


int main(){
    int x = 10;
    int y = 1;
    PRINT_2(x, y);
    printf(TEXT(x - 1, y + 3));

    #define X_N(N) x ## N // Create xN variable
    int x4 = 10;
    printf("%d\n", X_N(4));
    return 0;
}