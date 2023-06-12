#include <stdio.h>
#include <stdlib.h>
#define LEN 6
void save_state();

int main(){
    for (int i = 0; i < 10000; i++)
        save_state();
}

void save_state(){
    // Convert from block scope to file scope
    static unsigned int counter = 0;
    printf("%d ", counter++);
}