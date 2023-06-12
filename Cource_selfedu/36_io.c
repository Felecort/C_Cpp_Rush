#include <stdio.h>
#include <stdlib.h>


int main(void){
    char sp[] = "Hello, world";
    printf("ch = %s\n", sp);
    // Auto \n
    puts(sp);
    puts(sp);

    char bf[10];
    // 9 - max limit to read. It's important
    // scanf("%9s", bf);
    // puts(bf);

    // Safety
    fgets(bf, sizeof(bf), stdin);
    puts(bf);


    return EXIT_SUCCESS;
}