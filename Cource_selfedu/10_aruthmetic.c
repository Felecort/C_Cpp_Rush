#include <stdio.h>


int main(){
    int count1 = 0, count2 = 0;
    int var1 = 0, var2 = 0;
    var1 = count1++;
    var2 = ++count2;
    

    printf("count++: %d, ++count: %d", var1, var2);
    return 0;
}