#include <stdio.h>

int main(){
    // Not
    unsigned char var = 154; //     -> 10011001
    unsigned char not_var = ~var; //  -> 01100110
    printf("var = %d, not var: %d\n\n", var, not_var);

    unsigned char flags = 5;
    unsigned char mask =  0b1001;
    unsigned char res = flags & mask;

    if ((flags & mask) == mask){
        printf("2nd bit included\n");
    }
    printf("res = %d\n\n", res);

    return 0;
}