#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(void)
{
    int status = EXIT_SUCCESS;
    FILE *in;

    struct sigrecord{
        int signum;
        char signame[10];
        char sigdesc[100];
    } sigrec;

    if ((in = fopen("./data/signals.txt", "r")) == NULL){
        fputs("Cannot open signals.txt \n", stderr);
        return EXIT_FAILURE;
    }

    do {
        int n = fscanf(in, "%d%9s%*[ \t]%99[^\n]",
                        &sigrec.signum, sigrec.signame, sigrec.sigdesc);
        if (n == 3){
            printf("Signal \n\tnumber = %d \n\tname = %s \n\tdescription = %s \n\n", 
                    sigrec.signum, sigrec.signame, sigrec.sigdesc);
        }
        else if (n != EOF){
            printf("Failed to match signal\n");
            status = EXIT_FAILURE;
            break;
        }
        else {
            break;
        }
    } while (1);

    if (fclose(in) == EOF){
        fputs("Failed to close file\n", stderr);
        status = EXIT_FAILURE;
    }
    return status;
}