#include <stdio.h>

void main(){
  int notprime = 0;
  for (int i=2; i <= 100; i++) {
    for (int j = 2; j < i; j++) {
      if(i % j == 0){
        notprime = 1;
      }
    }
    if(notprime == 0){
      printf("%d\n", i);
    }
    notprime = 0;
  }
}
