#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char *argv[]){
    for (size_t i = 0; i < argc-1; i++){argv[i] = argv[i+1]; }
    if (execvp(argv[0],argv) < 0) {     /* execute the command  */
        printf("*** ERROR: exec failed\n");
        exit(1);
    }
}