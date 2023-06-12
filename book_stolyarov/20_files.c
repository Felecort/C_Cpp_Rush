#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    FILE *f;
    f = fopen("20_from.txt", "w");
    if (!f){
        perror("20_from.txt");
        return 1;
    }
    
    double sin_value, cos_value, radians, angle;
    radians = (2. * M_PI) / 360.;
    
    for (int degree = 0; degree < 360; degree++){
        angle = (double)degree * radians; // double
        sin_value = sin(angle);
        cos_value = cos(angle);
        fprintf(f, "%03d\t% 7.5f\t% 7.5f\n", degree, sin_value, cos_value);
    }
    fclose(f);
    return 0;
}