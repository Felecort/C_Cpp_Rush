#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct init {
    double d1;
    double d2;
    // Error
    // double func(){
    //     return 0.4;
    // }
};

int main(void)
{
    
    struct init st = {2.3, 5.5};
    printf("d1 = %f, d2 = %f", st.d1, st.d2);

    return EXIT_SUCCESS;
}