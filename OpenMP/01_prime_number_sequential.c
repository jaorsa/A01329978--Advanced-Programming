#include <stdio.h>
#include <stdlib.h>
// #include "omp.h"
#include <math.h>
#include <time.h>

void main(){
    clock_t end, begin;
    double final;
    int flag = 1, range;
    printf("Sequential: \n");
    
    // inicio=omp_get_wtime();
    scanf("%d", &range);
    begin = clock();
    // #pragma omp for schedule(static)
    for (int n = range; n > 0; n--)
    {
        for (int i = 2; i <= sqrt(n); i++) 
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
        if(n <= -1){break;}
    }
    // final = omp_get_wtime();
    end = clock();
    final = end - begin;   
    printf("time: %f\n", final);
}