#include <stdio.h>

void main(){
  int first, second, third;

  scanf("%d", &first);
  scanf("%d", &second);
  scanf("%d", &third);

  if(first + second + third == 180 && first!= 0 && second != 0 && third != 0){
    printf("it's possible\n");
  }
  else{
    printf("not possible\n" );
  }
}
