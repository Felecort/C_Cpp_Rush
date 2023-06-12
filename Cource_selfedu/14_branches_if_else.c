#include <stdio.h>


int main(){
    int x;
    if (scanf("%d", &x) != 1){
        printf("Error");
        return 0;
    }

    if (x < 0) x = -x;
    printf("%d", x);

    return 0;
}