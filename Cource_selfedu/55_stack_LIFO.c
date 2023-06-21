#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct tag_object {
    int data;
    struct tag_object *next;
} OBJ;

OBJ *push(OBJ* top, int data)
{
    OBJ *ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;

    return ptr;
}

OBJ *pop(OBJ *top)
{
    if (top == NULL){
        return top;
    }
    printf("Deleted obj: %d\n", top->data);
    OBJ *ptr_next = top->next;
    free(top);
    return ptr_next; 
}

void show(const OBJ* top){
    const OBJ *current = top;
    while(current != NULL){
        printf("%d \n", current->data);
        current = current->next;
    }
}

int main(void)
{
    OBJ *top = NULL;
    for (int i = 0; i < 5; i++)
        top = push(top, i);
    
    show(top);

    while (top != NULL){
        top = pop(top);
    }

    return EXIT_SUCCESS;
}