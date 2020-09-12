/*
 * Jacqueline Ortiz Sánchez A01329978
 * Programa 5
 * Programa recibe un número y regresa el factorial llendo de 1 hasta n
 * Si recibe un numero negativo lo vuelve positivo y si recibe 0, lo imprime
 *
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  int n, factorial = 1;
  printf("Please enter a number : " );
  scanf("%d", &n);
  if(n == 0){
    printf("The factorial of 0 is %d\n", factorial);
  }

  if(n < 0){
    n = n*-1;
  }

  for (int i = 1; i <= n; i++) {
    factorial *= i;
  }
  printf("The factorial of %d is %d\n", n, factorial);
}
