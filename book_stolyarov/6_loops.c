#include <stdio.h>


int main(){
    int x = 0;
    do{
        x++;
        printf("%d\n", x);
    } while (x < 10);

    for (int i = 1; i < 12; i++){
        printf("%d x %d\t = %d\n", i, i, i * i);
    }

    // double k, s;
    // int n;
    // for (s = 0; (n = scanf("%lf", &k)) == 1; s += k){
    //     printf("k = %f, s = %f, n = %d\n", k, s, n);
    // }
    return 0;
}