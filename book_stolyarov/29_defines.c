#include <stdio.h>

#define BUFFER_SIZE 1024
#define HELLO_MSG "Hello, world\n"
#define MALLOCITEM malloc(sizeof(struct item))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define HELP_TEXT \
    "this is a very"\
    "large text"\
    "..."
#define MAKE_ARRAY_SUM_FUNCTION(FUNNAME, TYPE) \
    TYPE FUNNAME (const TYPE *a, int n)\
    {\
    TYPE s = 0; \
    while (n > 0) { \
        s += *a; \
        a++; \
        n--; \
    } \
    return s; \
    }

// If we want to call macro as a func with `;` in the end
#define MYMACRO(arg) do {f(arg); g()} while(0)
// Creation two functions using macro
MAKE_ARRAY_SUM_FUNCTION(int_sum, int)
MAKE_ARRAY_SUM_FUNCTION(double_sum, double)
// "delete" my macro
#undef MYMACRO

struct item{
    int width, height;
    char name[10];
};

int main(){
    // Macrocall
    // char BUFFER[BUFFER_SIZE];
    int x[4] = {1, 2, 3, 4};
    int sum_of_x = int_sum(x, 4);
    printf("%d\n", sum_of_x);
    printf("%s", __FILE__);

    return 0;
}