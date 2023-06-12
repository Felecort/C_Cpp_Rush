#include <stdio.h>


int main(){
            //    0     1       2...
    enum colors {red, orange, yellow, green, blue, violet};
    enum colors one_color = 5; // data type
    printf("%d, %d\n", red, one_color);
    
    enum {bipolar, field};

    enum transistors {
        PNP = 12,
        NPN = 7,
    };
    
    // Type and variables
    enum states{running, blocked, ready} new_state, last_state;
    printf("%d, %d, %d", running, new_state, last_state);

    return 0;

}