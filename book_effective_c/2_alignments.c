#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

struct S{
    int i;
    double d;
    char c;
};

struct align16{
    float data[4];
};

int main(){
    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

    struct S *bad_s_ptr = (struct S *)bad_buff;     // Wrong alignment
    struct S *good_s_ptr = (struct S *)good_buff;   // Correct alignment


    alignas(32) struct align16 a, b;
    struct align16 c;
    // a and b diffrent by 32 bytes, c is random
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    return EXIT_SUCCESS;
}