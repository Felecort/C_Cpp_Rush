#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct widget {
    char c[10];
    int i;
    double d;
} widget;

int main(void){
    widget *p = (widget *)malloc(sizeof(widget));
    if (p == NULL){
        return 1;
    }

    widget w = {"abcdefhig", 9, 3.14};
    memcpy(p, &w, sizeof(widget));

    int *arr = calloc(4, 10);
    // for (int i = 0; i < 10; ++i)
    //     arr[i] = i;
    for (int i = 0; i < 10; ++i)
        printf("%d", arr[i]);
}