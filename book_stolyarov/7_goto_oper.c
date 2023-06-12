#include <stdio.h>


int main(){
    int i = 0;
    label:
    
    i++;
    printf("%d\n", i);
    if (i > 10) return 0;
    
    goto label;
    return 0;
}