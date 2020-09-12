#include <stdio.h>
#include <stdlib.h>
void main(){
  char text[50];
  int words=0;
  scanf("%[^\n]", text );
  char *ptr = text;

  if(text[0] != ' '){
    words++;
  }
  for (; ptr < &text[50]; ptr++) {
    if(*ptr == 32){
      words++;
    }
  }
  
  printf("There are\n");
  printf("%d words \n", words);
}
