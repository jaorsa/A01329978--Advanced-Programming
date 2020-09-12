#include <stdio.h>

void main(){
  int x;

  scanf("%d", &x);
  for (int i=0; i <= 10; i++) {
    printf("%d\n", x*i);
  }
}
