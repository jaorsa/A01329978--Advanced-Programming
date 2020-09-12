#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fibonacci(long long n){
  int n1 = 0, n2 = 1, f;
    for (int i = 3; i <= n; i++) {
      f = n1 + n2;
      n1 = n2;
      n2 = f;
      printf("index %ld es %ld\n", i, f );
    }
    return f;
}

int main(){
  clock_t start = clock();
    fibonacci(100);
    clock_t end = clock();
    printf("start %ld\n",start);
    printf("end %ld\n", end);
    printf("diff %ld\n", start - end);
    return 0;
}
