#include <stdio.h>

int main(){
    int item;
    
    if (scanf("%d", &item) != 1)
    {
        printf("Eror input");
        return 0;
    }

    switch (item)
    {
        case 1:
            printf("hello 1\n");
            break;
        case 2:
            printf("Hello 2\n");
            break;
        default:
            printf("Aboba\n");
            break;
    }

    char ch_item;
    if (scanf("%c", &ch_item) != 1){
        printf("error input");
        return 0;
    }

    switch (ch_item)
    {
        case 'a':
        case 'A':
            printf("Symbol A\n");
            break;
        case 'b':
        case 'B':
            printf("Symbol b\n");
            break;
        case 'c':
        case 'C':
            printf("Symbol b\n");
            break;
        default:
            printf("Unknown symbol\n");
            break;
    }
    return 0;
}