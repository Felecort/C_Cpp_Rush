#include <stdio.h>

union sample_un{
    int i;
    double pi;
    char str[4];
    char symbol;
};

union split_int{
    int integer;
    unsigned char bytes[sizeof(int)];
};

int main(){
    int i;
    union split_int si;
    printf("Enter number: ");
    scanf("%d", &si.integer);
    for (i = 0; i < sizeof(int); i++)
        printf("Byte#%d is %02x\n", i, si.bytes[i]);

    return 0;
}