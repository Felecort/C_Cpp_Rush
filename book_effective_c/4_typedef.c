#include <stdio.h>
#include <stdlib.h>

signed char *func(void){
    printf("I'll return ref for char and take no args!\n");
    signed char *data;
    *data = 97;
    return data;
}


int main(void){
    // (*)
    typedef signed char *(*fp)(void);
    
    signed char *value;
    fp function_def;
    
    function_def = &func;
    value = function_def();
    
    printf("%c", *value);

    return EXIT_SUCCESS;
}
