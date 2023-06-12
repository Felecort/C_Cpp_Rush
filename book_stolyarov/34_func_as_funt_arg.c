#include <stdio.h>
int is_negative(int x) {return x < 0;}
int is_even(int x) {return x % 2 == 0;}
int is_div7(int x) {return x % 7 == 0;}


void delete_from_int_list(struct item **pcur, int (*crit)(int))
{
    while (*pcur){
        if ((*crit)((*pcur)->data)) {
            struct item *tmp = *pcur;
            *pcur = (*pcur)->next;
            free(tmp);
        } else {
            pcur = &(*pcur)->next;
        }
    }
}



int main()
{
    // func as arg
    delete_from_int_list(&first, &is_div7);
    return 0;
}