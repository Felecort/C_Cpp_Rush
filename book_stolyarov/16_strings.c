#include <stdio.h>


int str_length(const char *str){
    // int i;
    // i = 0;
    // while (str[i] != '\0')
    //     i++;
    // return i;

    // int i;
    // for (i = 0; str[i]; i++)
    //     {}
    // return i;

    const char *p;
    p = str;
    while (*p)
        p++;
    return p - str;
}

void str_copy(char *dest, const char *src){
    // int i;
    // for (i = 0; src[i]; i++)
    //     dest[i] = src[i];
    // dest[i] = 0; // !!!!!!!


    // while (*src){
    //     *dest = *src;
    //     dest++;
    //     src++;
    // }
    // *dest = 0;


    for (; *src; dest++, src++)
        *dest = *src;
    *dest = 0;

}


int main(){
    // MUTABLE 
    char str[] = "hello world";
    printf("%c\n", str[0]);
    str[2] = (char)97;
    printf("%s\n", str);

    // IMMUTABLE
    char *ptr = "hello world";
    printf("%d\n", sizeof(ptr));
    printf("%c\n", ptr[0]);
    // No error, but error :)
    // ptr[0] = 'A';
    // printf("%c\n", ptr[0]);

    printf("str size: %d\nptr size: %d", sizeof(str), sizeof(ptr));
    


    return 0;
}