#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

void main() {
    double inicio, final;
    int n2 = 1, n1 = 0, next = 0, n;
    printf("Parallel: ");
    scanf("%d", &n);
    inicio=omp_get_wtime();

    printf("Fibonnaci sequence: \n");
    
    #pragma omp for schedule(static)    
    for(size_t i = 1; i <= n-1; i++) {
        next = n1 + n2;
        printf("%d \n", next);

        n1 = n2;
        n2 = next;
    }
    final = omp_get_wtime();
    final -= inicio;   
    printf("time: %f\n", final);
}