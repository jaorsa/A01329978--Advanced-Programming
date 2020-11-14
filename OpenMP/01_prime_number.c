#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

void main(){
    double inicio,final,tiempo;
    size_t flag = 1, range;

    inicio=omp_get_wtime();
    scanf("%d", &range);
    #pragma omp for schedule(static)
    for (size_t n = range; n > 0; n--)
    {
        for (size_t i = 2; i <= sqrt(n); i++) 
        { 
        // If n is divisible by any number between 
        // 2 and n/2, it is not prime 
            if (n % i == 0) { 
                // printf("%d is not prime\n", n);
                flag = 0; 
                break; 
            } 
        }
        if(flag == 1){printf("%d is prime\n", n);}
        flag = 1;
    }
    final = omp_get_wtime();
    final -= inicio;
    printf("time: %f\n", final);
}