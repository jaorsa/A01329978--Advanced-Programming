#include <stdio.h>
#include <stdlib.h>


size_t sizeArray = 0, line = 1;
//        lines chars       
char lines[50][100];

//Find char in file
void findChar(FILE *ptr){
  char tmp;
  char *file = (char*)calloc(sizeArray, sizeof(char));
  char lines[50][100];


  //count the number of lines 
  while(fscanf(ptr, "%c", &tmp) != EOF){

    lines[line-1][sizeArray] = tmp;
    sizeArray++;

    if( tmp == '\n'){
      line++;
      sizeArray = 0;
    }
  }
  
  printf("The number of lines found in the file are: %d\n", line);
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
