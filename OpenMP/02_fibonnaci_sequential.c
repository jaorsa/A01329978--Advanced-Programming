#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    clock_t end, begin;
    double final;
    int n2 = 1, n1 = 0, next = 0, n;
    printf("Sequential: ");
    scanf("%d", &n);
     begin = clock();

    printf("Fibonnaci sequence: \n");
    for(int i = 1; i <= n-1; i++) {
        next = n1 + n2;
        printf("%d \n", next);

        n1 = n2;
        n2 = next;
    }
    end = clock();
    final = end - begin;   
    printf("time: %f\n", final);
}