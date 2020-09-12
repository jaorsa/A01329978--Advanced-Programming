/*
 * Jacqueline Ortiz Sánchez A01329978
 * Programa 3
 * Solo los usuarios de Juan y Ana reciben el mensaje de bienvenida
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(){
  char name[20];
  printf("Please enter your name: " );
  scanf("%s", &name);
  //To test if every case works
  for (int i = 0; i < strlen(name); i++) {
    name[i] = tolower(name[i]);
  }
  //Compares strings
  if( strcmp(name, "juan") == 0 || strcmp(name,"ana") == 0){
    printf("Nice to meet you %s\n",name);
  }

}
