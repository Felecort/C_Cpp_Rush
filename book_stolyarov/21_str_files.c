#include <stdio.h>



int main(){
    // fputs("Hello world", stdout);

    FILE *f;
    f = fopen("20_to.txt", "r");
    if (!f){
        perror("20_to.txt");
        return 1;
    }
    char string[50];
    fgets(string, 50, f);
    printf(string);



    return 0;
}