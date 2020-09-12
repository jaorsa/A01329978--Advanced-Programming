/*
 * Jacqueline Ortiz Sánchez A01329978
 * Programa 4
 * Programa recibe un número y regresa la suma llendo de 1 hasta n
 * Si recibe un numero negativo lo vuelve positivo y si recibe 0, lo imprime
 *
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  int n, suma = 0;
  printf("Please enter a number : " );
  scanf("%d", &n);
  if(n == 0){
    printf("The addition is %d\n", suma);
  }

  if(n < 0){
    n = n*-1;
  }

  for (int i = 1; i <= n; i++) {
    suma += i;
  }
  printf("The addition from 1 to %d, is:  %d\n", n, suma);
}
