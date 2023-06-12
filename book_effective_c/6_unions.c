#include <stdio.h>
#include <stdlib.h>



int main(void){
    // Sequence is important
    union my_union{
        struct {
            int type;
        } n;
        struct {
            int intnode;
            int type;
        } ni;
        struct{
            int type;
            double doublenode;
        } nf;
    } u;
    // all vars type are equal to 1
    u.nf.type = 1;
    u.nf.doublenode = 3.14;

    // all vars intnode are equal to 23
    u.ni.intnode = 23;
    // all vars type are equal to 1
    u.ni.type = 77;


    return EXIT_SUCCESS;
}