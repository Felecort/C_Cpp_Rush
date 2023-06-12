#include <stdio.h>

// Will show warning, because not every constant proceed
enum greek {alpha, beta, gamma = beta, delta};
void greek_print(enum greek x){
    switch (x)
    {
    case alpha:
        printf("ALPHA");
        break;
    case beta:
        printf("BETA");
        break;
    }
}


int main(){
    // Early constants
    enum {max_bufer_size = 1024};
    // max_bufer_size = 10; - error. Unmutable.
    printf("mbs = %d", max_bufer_size);

    enum greek {alpha, beta, gamma = beta, delta};


    return 0;
}