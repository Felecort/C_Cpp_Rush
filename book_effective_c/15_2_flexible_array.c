#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    size_t num;
    int data[];
} widget;

void *func(size_t array_size){
    widget *p = (widget *)malloc(sizeof(widget) + sizeof(int) * array_size);
    if (p == NULL)
        return NULL;
    p->num = array_size;
    for (size_t i = 0; i < p->num; ++i)
        p->data[i] = i;
    return p;
}


int main(void)
{
    widget *arr = func(12);
    for (int i = 0; i < 12; i++)
        printf("%d ", arr->data[i]);
    
    
    return EXIT_SUCCESS;
}