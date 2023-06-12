#include <stdio.h>
#include <stdlib.h>

enum {max_name_len = 64, max_group_len = 8};

// student - struct name
// struct student - data type
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
    // to = from;   
}


int main(){
    // Define structure
    struct student st1;

    // Assignmant variables
    copy_string(st1.name, "abober");
    st1.sex = 'm';
    st1.year_of_birth = 1997;
    st1.major_code = 57863;
    st1.year = 3;
    copy_string(st1.name, "123");
    st1.average = 3.1;

    // Or initialization
    struct student st2 = {
        "Viktor Bobrov",
        'm', 1995, 56773, 3, "321", 2.3
    };
    return 0;
}