#include "is_prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>


typedef unsigned long long *ull_ptr;
typedef unsigned long long ull;

// 10.2
// Print command line help text
static void print_help(void)
{
    printf("%s", "primetest num 1[num2 num3 ... numN]\n\n");
    printf("%s", "Tests positive integers for primality. Supports testing ");
    printf("%s [2-%llu].\n", "numbers in the range", ULLONG_MAX);
}

// 10.3
static bool convert_args(const char *arg, ull_ptr val)
{
    char *end;

    // strtoll returns an in-band error indicator; clear errno
    errno = 0;
    *val = strtoull(arg, &end, 10);

    // Check for failures where the call returns a sentinel value and sets errno
    if ((*val == ULLONG_MAX) && errno) return false;
    if (*val == 0 && errno) return false;
    if (end == arg) return false;

    if (*val <= 1) return false;
#ifdef DEBUG
    printf("\nConverting complete\n");
#endif

    return true;
}

// 10.4
ull_ptr convert_command_line_args(int argc,
                                  char *argv[],
                                  size_t *num_args)
{
    *num_args = 0;
    if (argc <= 1){
        // No args
        print_help();
        return NULL;
    }
    ull_ptr args = (ull_ptr)malloc(sizeof(ull) * (argc - 1));
    bool failed_conversion = (args == NULL);

    for (int i = 1; i < argc && !failed_conversion; i++){
        // Attempt tp convert the arg into an integer
        ull one_arg;
        failed_conversion |= !convert_args(argv[i], &one_arg);
        args[i - 1] = one_arg;
    }
    if (failed_conversion){
        // Free the array
        free(args);
        print_help();
        return NULL;
    }
    *num_args = argc - 1;
    return args;
    
}



// 10.7
int main(int argc, char *argv[])
{
    size_t num_args;
    ull *vals = convert_command_line_args(argc, argv, &num_args);

    if (!vals) return EXIT_FAILURE;

    for (size_t i = 0; i < num_args; i++){
        printf("%llu is %s. \n", vals[i], is_prime(vals[i], 100) ? "probably prime" : "not prime");
    }

    free(vals);

    return EXIT_SUCCESS;
}