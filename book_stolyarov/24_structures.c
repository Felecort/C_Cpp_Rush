#include <stdio.h>
#include <stdlib.h>

enum {max_name_len = 64, max_group_len = 8};

struct student{
    char name[max_name_len];
    char sex;
    int year_of_birth;
    int major_code;
    int year;
    char group[max_group_len];
    float average;
};


void copy_string(char *to, char *from){
    while (*from != '\0')
    {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0'; 
}


int main(){
    struct student *ptr;
    // Dynamic mamory allocation
    ptr = malloc(sizeof(struct student)); 
    // Or
    ptr = malloc(sizeof(*ptr));
    printf("%d", sizeof(*ptr)); 
    // Assign value to the field using pointer for structure
    ptr->average = 10;
    
    return 0;
}