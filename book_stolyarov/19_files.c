#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char **argv){
    // FILE *f;
    // f = fopen("19_file.txt", "w");
    // if (!f){
    //     perror("19_file.txt");
    //     exit(1);
    // } 
    // return 0;

    FILE *from, *to;
    int c, lcnt;
    int lines = 10;
    if (argc < 3){
        fprintf(stderr, "Too few argumants\n");
        return 1;
    }
    from = fopen(argv[1], "r");
    if (!from){
        perror(argv[1]);
        return 2;
    }
    to = fopen(argv[2], "w");
    if (!to){
        perror(argv[2]);
        return 3;
    }

    lcnt = 0;
    while ((c = fgetc(from)) != EOF){
        fputc(c, to);
        if (c == '\n')
            lcnt++;
        if (lcnt >= lines)
            break;
    }
    return 0;


}