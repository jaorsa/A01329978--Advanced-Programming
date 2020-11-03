#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


unsigned long long fact = 1;

void sigint_handler(int number){ printf("The last number found is: %lld\n", fact); }

void factorial(long long last){
    if(last == 0){ printf("The factorial of 0 is %d\n", fact); }

    if(last < 0){ last = last*-1; }

    for (unsigned long long i = 1; i <= last; i++) { fact *= i; sleep(1);}
    
}

void main(int argc, char *argv[]){
    unsigned long long last;
    last = atoll(argv[1]);
    signal(SIGINT, sigint_handler);
    factorial(last);
}