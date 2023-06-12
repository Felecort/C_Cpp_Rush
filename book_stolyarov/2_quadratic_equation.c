#include <stdio.h>
#include <math.h>


double discriminant(double a, double b, double c){
    return (b * b) - (4 * a * c);
}

int main(){
    double p, q, r, d;
    int n;
    n = scanf("%lf %lf %lf", &p, &q, &r);
    if (n != 3){
        printf("Error. Interpreter as %.2f, %.2f, %.2f\n", p, q, r);
        return 1;
    }
    if (p == 0){
        printf("Error! Not a quadratic equation");
        return 2;
    }
    d = discriminant(p, q, r);
    if (d < 0){
        printf("No real roots");
        return 0;
    }
    d = sqrt(d);

    printf("root1: %.2f\nroot2: %.2f\n", (-q - d) / (2 * p),
                                        (-q + d) / (2 * p));
    return 0;
}