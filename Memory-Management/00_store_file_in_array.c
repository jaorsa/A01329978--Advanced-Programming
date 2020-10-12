#include <stdio.h>
#include <stdlib.h>


size_t sizeArray = 0, line = 1;
//        lines chars       
char lines[50][100];

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
     
  printf("The content of the file says the following:\n" );
  
   for (size_t i = 0; i < line; i++)
  {
    printf("Line %d says: %s", i, *(lines+i));
  }
  
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
