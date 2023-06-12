#include <stdio.h>


int main(){
    int g = 4;
    int *ptr_g = &g;
    printf("ptr = %u\n", ptr_g);
    ptr_g--;
    printf("ptr = %u\n", ptr_g);
    ptr_g += 4;
    printf("ptr = %u\n", ptr_g);

    int a = 1, b = 2;
    int *ptr_a = &a, *ptr_b = &b;
    
    int res = ptr_a - ptr_b;
    
    printf("ptr_a = %u, ptr_b = %u diff b, a = %d\n\n" ,ptr_a, ptr_b, res);
    
    int x = 476789;
    char *ptr_x = (char *)&x;
    // [117, 70, 7, 0] int 4 bites
    for  (int i = 0; i < sizeof(int); i++){
        printf("%d ", *ptr_x);
        ptr_x++;
    }

}


