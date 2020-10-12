#include <stdio.h>
#include <stdlib.h>


size_t sizeArray = 0, line = 1;
//        lines chars       
char lines[50][100];

void findChar(FILE *ptr){
  char tmp;
  char *file = (char*)calloc(sizeArray, sizeof(char));
  int characters = 0, words = 0;
  char lines[50][100];


  //count the number of lines 
  while(fscanf(ptr, "%c", &tmp) != EOF){

    lines[line-1][sizeArray] = tmp;
    sizeArray++;

    if( tmp == '\n'){
      line++;
      sizeArray = 0;
      characters-=2;
    }

    //counting words and characters
    if(tmp == ' ' || tmp == '.'){
      words++;
    }
    characters++;
      
  }
  
  printf("The number of words is: %d, the number of characters found in the open file is: %d \n ", words, characters);
  free(file);

}


void main(){
  FILE *ptr;
    ptr = fopen("input.txt", "r+");

  if(ptr == NULL){
    printf("Archivo inexistente\n");
    exit(1);
  }

findChar(ptr);
fclose(ptr);
}
