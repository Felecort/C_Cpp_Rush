#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_str_equal(const char *, const char *);

int main(void){
    char s1[12] = "Hello";
    char s2[10] = "Hel lo";

    printf("%d\n", is_str_equal(s1, s2));

    const char *strings[] = {"Ship", "Shopping", "Shame", "Shadow"};
    for (int i = 0; i < 20; i++)
        printf("%c", strings[0][i]);
    puts("");
    for (int i = 0; i < 4; i++)
        printf("%s", strings[i]);

    return EXIT_SUCCESS;
}


bool is_str_equal(const char *ptr_s1, const char *ptr_s2){
    while (*ptr_s1 != '\0' || *ptr_s2 != '\0'){
        if (*ptr_s1 != *ptr_s2) return false;
        ptr_s1++;
        ptr_s2++;
    }
    return true;
}