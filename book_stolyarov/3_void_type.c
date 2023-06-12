#include <stdio.h>


void print_n_chars(char c, int n){
    int k;
    for (k = 0; k < n; k++){
        printf("%c", c);
    }
    printf("\n");
}


int main(){
    char c = 'a';
    int n = 10;
    print_n_chars(c, n);
    return 0;
}