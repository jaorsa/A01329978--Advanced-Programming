#include <stdio.h>
#include <stdlib.h>
void main(){
  char text[50];
  int words=0;
  scanf("%[^\n]", text );
  char *ptr = text;

  
  printf("There are\n");
  printf("%d words \n", words);
}
