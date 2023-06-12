#include <stdio.h>
#define TOTAL_MARKS 10

int main()
{
    
    int marks[TOTAL_MARKS] = {1, 2, 3};

    marks[2] = 3;
    marks[0] = 2 * 3;
    // size_t bytes_marks = sizeof(marks); // data type unsigned long int
    const int *ptr;
    ptr = marks;
    printf("marks %d\n", sizeof(marks));
    printf("ptr %d\n", sizeof(ptr));
    return 0;
}