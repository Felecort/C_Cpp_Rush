# Compile program

`-Wall` - warnings all: show all warnings  
`-g` - debug information  
`-o` - output file name  
`-lm` - clearly include math library (use after source files)   
`-S -fverbose-asm` - get asm code with comments  
`-c` - get object file (need for separate translation)  
`-E` - Create file after macroprocessing  
`-O<level>` - optimization level  
`-D <MACROMANE=VALUE>` - allows to define macro in the command line 
`-I <lib>` - include additionsl libraries  
`-static` turn off dynamic libraries  

## Separate translation  
1. Create a defenition of function in main  
`<type> some_func(args);`    
`gcc -Wall -g -c mod.c`  
`gcc -Wall -g main.c mod.o -o program.exe`  
2. Use static for functions that you don't use in main  
3. Create header for all files exclude `main`  
3. Aviod numerous includind in .h (sentry marcos):  
```c
#ifndef <MODULENAME>_H_SENTRY
#define <MODULENAME>_H_SENTRY
/* code */
#endif
```

# Initialization, definition and assignment

`int var_init = 10;` - initialization  
`int var_def;` - defenition  
`var_def = 10;` - assignment  
Assignment is destructive operation, that rewrite memory  


## Global 
Very fast, compiler doest't spent more time to locate variables in the .exe file   
Variables below are static (address doesn't change)  
`int global_var;` - fill zeros (because sends to the .bss section in asm)  
`int var_init = 10;` - Sends to .data section in asm  

## local  
Longer then global, because we net clearly point for some memory locaton  
`int local_var;` - fill with random trash, because it's too long every time fill zeros the stack frame   

# Data types  
Int and float. Thats all.  
By defoult char may be or signed or unsigned. With othe types we have not this problem.  

Integers: char < short < int < long < long long  
Floats: float < double < long double  
Do not use float, while you don't faced with low memory  
Char size by default is equal 1  
`sizeof(char);` -> `sizeof(1)`  

`typeof` equal `unsigned long int`  

 
## Wraparound  
Equal to overflow some dtype  

## Declarations and defenitions  

`int var;`  ->  declaration and definition  
`extern int var;`  -> declaration  
`extern` means that some var defined somewhere (use fore more src files)    
When we define functions prototype, we imply `extern` keyword
## Floats  
floats have nans, inf, and other  


# Operators  
In C we have no assignment operator. Only just assignment for  
`sizeof x` will compile correct, because sizeof not a function but operator  

# Pointers  
Pointers contain int data representation, but when we define pointer, we must use the same type as a data  
`double *x = &y;` - x is int pointer for double data  
`*x` - return **value**, that placed in pointer x  
`&x` - return **pointer** for data   

## Using pointers  
`char *ptr;` - Define pointer 
`ptr = 0;` - Assign **address (pointer)**
`*ptr = 0;` - Assign **value**

## Address arithmetic  
Pointer's value as changes as size data type    
Indexin in C is not operations on the array, it's operations on the addresses  

## Arrays  
`m[a] is equal *(m + a) is equat a[m]`  
`[]` - is an arithmetic operation (with poiter)  
`int arr[20] = {1, 2, 3};` - Other element will be equal to `0`  
`int arr[20] = {};` - zero array  
`int digits[10] = {[3] = 55, [6] = 99};` - particular initialization  
`int var;`
`int arr[] = {1, 2, var, 4, 5};` - We can use variables in arr  


## Multidimentional arrays  
`int arr[][];`, `arr` - is a pointer for array. Not a pointer for the first element  
C have not arrays, but have pointers for arrays. :)  
`int (*p)[N]` - data type for `arr[M][N]`. NOT `int *q[4]`!  
for `int z[10][15][20];` dtype is `int (*zptr)[15][20];`

## Multidimentional arrays with no fixed size  
Passing array with no constant size  
```C
int matrix_sum(size_t rows, size_t cols, int m[rows][cols]){
    int total = 0;
    for(size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < cols; c++)
            total += m[r][c];
    return total;
}
```

# Static variables  
Static variables exist while program run, and save it's state between func calls. Static means the addres of variable doesn't change.  
Static doesn't use space in stack-frame, it's allocate in .bss  
Static let us convert var from block scope to file scope, but not share var for other files.  
```c
void save_state(){
    static unsigned int counter = 0;
    printf("%d\n", counter++);
}
```  
Static variables must have constants in compile time

```C
int main(void){
    int i; // automatic variable
    static int st; // Static var. Equal zero by default
}
```

# Strings  
The most frequent location for the string in .asm is .text section in unmutable memory  
`char str[] = "hello world"` - in the mutable memory  
`sizeof(str)` -> 12 size of array (length)
`char *ptr = "hello world` - in the immutable memory  
`sizeof(ptr)` -> 4. Size of pointer (char)  

`char` - type represents *narrow character* in 8 bits  
`wchar_t` - represent *wide character*. more than 8 bits (16)  

`None` - int
`L'a'` - `w_char_t`  
`u'a'` - `char16_t`  
`U'a'` - `char32_t`  


# Command line args  
`int argc` - 1st arg is number of args  
`char **argv` - 2nd arg is arr of pointers on arrays  
`argc` must be = 1  
`argv[0]` - is program name and path


# Sequence points  
We have a lots of undefinites:  
`f(h1(), h2(), h3())`  
f will be calculated after h1, h2, h3. But sequence execution of hn is undefined. It's depends on optimization and smth else  
But Sequence point can tuny define the concequencec  
`;` - is Sequence point. All calculation that wold be put off are calculated  

# Standart input/output  
`int getchar();` have type int, because *end of file* doesn't include for range [0, 255]. EOF have code `-1`  

# Files  
`FILE*` - data type for working with files (pointer)  
Never copy `FILE` object
`fopen(<path>, <mode>)` - open file  
`fclose(FILE stream)` - close file  
`gets` - NEVER USE THIS CURSED FUNCTION  
Try to use `fputc` - it's more safer
`stdio.h` already include `stdout`, `stderr`, `stdin` and other functions that handle files with char or wchar_t  

To get position indicator use `ftell` or `fseek`. If index is large: `fgetpos` and `fsetpos`  


![alt text for screen readers](/.images/file_handler-funcs.jpg "Functions")  

# Structures  

`struct <name> {<fields>} [vars];` - basic syntax  
Size of structer more than sum of var sizes, because compiler use alingment bites. Processor demand placing some data in cells div by 2 or 4  
`struct student *ptr` - pointer for struct  
`*ptr.year` - **Error**!!!, `.` is more priority against `*`  
`(*ptr).year` - correct, but too long  
`ptr->year` = `(*ptr).year`, much more elegant  

## Structers with bites (not often use)  
```c
struct myflags{
    unsigned io_error:1;
    unsigned seen_a_digit:1;
    unsigned count:4;
};
```  
After `:` we show the number of bites  

# Unions  
Like structers, but can contain only one in particular moment  
Writing some value in union fiels rewrite old data. Union contain all data in one memory cell  

# Typedef  
All these types are unqualified  
Directive `typedef` allows to insert own data types. One of purpose is create synonim for something, or to shortcut crated struct type  
`typedef struct tag_mystruct {<variables>} mystruct` - here `mystryct` in new name of data type, we don't must use `struct tag_mystruct` as a data type name.  
`typedef int *intptr` now type `intptr` is a pointer for integer  
But `typedef` is starting work only after defenition!  

`fp` - function name, but it return **not** a pointer. 
`typedef signed char (*fp)(void);`

# Qualified types  
Use keywords: `const, volatile, restrict, _Atomic`  

## Constants  
Const only for compiler, not for machine code  
`const ` - is not availabe in compiletime requirements (switch). Most commonly used with constant opointers:  
`const in *ptr;` - pointer for unmutable memory cell.  

## Constants in func args  
`void suspicious_funv(int *a);` - may change a given variable  
`void trustworthy_func(const int *a)` - Won't change recieving data (but can)  

## Volatile  
static volatile use for memory-mapped IO ports  
const volatile use for memory-mapped input ports (like clocks)  

## Restrict  
`restrict` var means that we have only one reference for this variable. It's allow compiler optimize code  

# Macroprocessor  
## Stages  

1. Lexical analisys  
Split text on lexems  
2. Macroprocessing  
3. Syntax analisys  
Use only capitalize symbols in macronames  

## Macro hack
If we want to call macro as a func with `;` in the end  
`#define MYMACRO(arg) do {f(arg); g()} while(0)`  


## Conditions in define  
```C
#if <defined constant or zero>
...;
#else 
...;
#endif
```  
We can check wether difined or not  
`#ifndef <MACRO>`  
`#define <MACRO> <VAL>`  
`#endif`  

`#if defined(DEBUG_PRINT) && DEBUG_PRINT > 7` - is equal `#ifdef`  

`#undef` - forgot about some defined macro  
`#error Something wrong` - abort program and show msg in std out  
`#line` - only for programs, witch C code created py other program  
`__LINE__, __TIME__, __DATE__, __FILE__, __STDC__` - defined by default and can not be changed  

## Includes  
Contain the defenisions of functions, but not functions self. It's ask to linker find functions and include it on the .exe. But sometimes output exe file doesn't constain functions exectry, insted while executions functions uploade from dynemic libraries  

`#include <smth.h>` - firstly search in sys catalogs, after in working  
`#include "smth.h"` - firstly search in working catalogs, after in sys  
(but not always)  

Contain booleans  
`#include <stdbool.h>`  
Contain limits for int dtype  
`#include <limits.h>`  
Like a config  
`#include <stdint.h>`  
`#include <inttypes.h>` 


# Random numbers  
For "real" random numbers you can use fopen and read specifir emul file.  
`1 + (int)(12.0 * rand() / (RAND_MAX + 1.0))` - for creatin a range  

# Variadic functions  
Can take variable nubmer of arguments  
`#include <stdarg.h>` - all instrumets here 
* Most important macro:  
`va_list` - dtype. First arg of other macro  
`va_start`  
`va_arg` - get arg
`va_end`  

Do not use without neccessary  
```C
int sum(int count, ...)
{
    int s = 0;
    va_list arg;
    va_start (arg, count);
    for (int i = 0; count > i; ++i)
        s += va_arg(arg, int);
    va_end(arg);
    return s;
}
```

## C haven't overload functions and base-args functions  

# Alignment  
Allows to align data  
`_Alignas` equal to `alignas` from `stdalign.h`  

# Functions  
`int fip()` - in C like a func that can accept any number of args, but in C++ it's a dunction that accsepts no args  
**Never declare function without parametrs**. use `void` to point for no args  


## Pointer for function  
`<type> (*<ptr_name>) (<args type>)`  

```C
int sq_rect(int width, int height)
{
    return width * height;
}

int (*ptr_sq_rect) (int, int);
```

## Array of pointers on function  
`<type> (*<arr_name>[<size>]) (args type)`


# IO
`scanf` - is not safety. Read while not \n or analogy. We can use int to poit how many symbols will be read: `"%9s"`   
`gets` - NO NO NO NO!  
`fgets` - Has an length arg


# Stack memory  

```C
double big_arr[1000000]; // Ok. But malloc better

int main(void){
    double arr[1000000]; // Error. Stack overflow
}
```  

# Increment / Decrement  
`i++` - returt, then increment  
`++i` - increment, then return  
decrement works similary  

`++i` equal to `i = i + 1`  

# Precedence and Associativity  
`a + b + c` equal to `((a + b) + c)` - right associativity  
`a = b = c` equal to `(a = (b = c))` - left associativity  

# Dynamic memory allocation  
`void *p = malloc(size)` - memory allocation  
`void *p = aligned_alloc(alingnment, size)` - alingment memory allocation  
`void *p = calloc(nmemb, size)` - allocate nmemb * size bytes  
`void *p = realloc(*ptr, size)` - reallocate memory  
If eny of this functions return NULL, it's an allocation error.  
`void free(*ptr)` - free allocated memory. 

## Good practise is set ptr to NULL after `free`:  
`free(*ptr); ptr = NULL;`  


# Entry point  
`main` - is a basic entry point, that takes *narrwo* character args - receives ANSI  
`wmain` - is the same, but with *wide* character args - receives UTF-16  


# Enum  
Enum defines in compile tome and can be used in `switch-case` operator. ordinary spell with lowercase.  
