#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fibonacci(long long n){
  int n1 = 0, n2 = 1, f;
    for (int i = 3; i <= n; i++) {
      f = n1 + n2;
      n1 = n2;
      n2 = f;
    }
    return f;
}

int main(){
  clock_t start = clock();

    for(long long i = 1; i <=100; i++){
        printf("index %ld es %ld\n", i, fibonacci(i) );
    }
    clock_t end = clock();
    printf("%ld\n",start);
    printf("%ld\n", start - end);
    return 0;
}
