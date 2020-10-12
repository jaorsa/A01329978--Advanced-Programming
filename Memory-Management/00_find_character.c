#include <stdio.h>
#include <stdlib.h>

/*
  Difference between a program, a thread, a task, a job and a process?
  
*/
size_t sizeArray = 0;

//Find char in file
void findChar(FILE *ptr){
  char tmp;
  char *file = (char*)calloc(sizeArray, sizeof(char));
  char buscando;
  int accum=0;
  printf("Type the character you wish to find\n");
  scanf("%c", &buscando);

  //count the number of lines 
  while(fscanf(ptr, "%c", &tmp) != EOF){

    
    sizeArray++;
    file = (char*)realloc(file, sizeArray * sizeof(char));
    if (tmp == buscando)
      accum++;
    *(file + sizeArray-1) = tmp;

    
  }
  printf("The character '%c' was found %d times in the file\n", buscando, accum);
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
