#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline, *sigline_p; // Global(?) variables


int main(void){
    struct sigrecord sig_local;
    struct sigrecord *sig_local_p;
    sig_local.signum = 10;
    sig_local_p->signum = 200;
    strcpy(sig_local.signame, "abober");
    strcpy(sig_local_p->signame, "baboner");
    return EXIT_SUCCESS;
}