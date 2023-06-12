#include <stdio.h>


int main(){
    int c, n;
    n = 0;
    while((c = getchar()) != EOF){
        printf("%c", c);
        if(c == '\n'){
            printf("Line length: %d\n", n);
            n = 0;
        } else {
            n++;
        }
    }
    return 0;
}