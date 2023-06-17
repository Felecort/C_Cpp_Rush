#include <stdio.h>
#include <stdlib.h>

enum {name_length = 50, b_length = 30};

struct tag_fio {
    char name[name_length];
    char last[name_length];
};

struct tag_person {
    struct tag_fio fio;
    char sex;
    unsigned short age;
    char b_date[b_length];
};

int main(void)
{
    struct tag_fio user_fio;
    struct tag_person user2;
    printf("tag_info size: %d, tag_person size: %d \n", sizeof(user_fio), sizeof(user2));

    struct tag_person person = {
        {"SirGay", "Balakiriev"},
        'M',
        98,
        "32.07.1925"
    };

    printf("Sex: %c, b_date: %s \n", person.sex, person.b_date);
    printf("name: %s, surname: %s \n", person.fio.name, person.fio.last);
    puts("------------------------- \n");
    struct tag_person person_2;
    person_2 = person;
    person.age = 123;
    printf("age person_2: %d \n", person_2.age);

    printf("person_1 ptr: %p, person_2 ptr: %p \n", person, person_2);

    return EXIT_SUCCESS;
}