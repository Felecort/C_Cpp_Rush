#define LANG_C

#if defined(LANG_C) // #ifdef
#   include <stdio.h>
#else
#   include <iostream>
#endif


int main(void){
    int x = 5;
#ifdef LANG_C
    printf("%d\n", x);
#else 
    std::cout << x << std::endl;
#endif
    return 0;
}