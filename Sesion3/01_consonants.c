#include <stdio.h>
#include <stdlib.h>
void main(){
  char text[20];
  int consonants=0, vocals=0;
  char *ptr = text;
  scanf("%[^\n]", text );
  for (; ptr < text.length; ptr++) {
    if(*ptr == 'a'|| *ptr == 'e'|| *ptr == 'i'|| *ptr == 'o'|| *ptr == 'u'){
      vocals++;
    }
    else{
      if(*ptr != '\0' && *ptr != ' ')
        consonants++;
    }
  }
  printf("There are\n");
  printf("%d consonants and %d vocals \n",consonants, vocals);
}
