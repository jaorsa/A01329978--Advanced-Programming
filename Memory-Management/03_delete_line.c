#include <stdio.h>
#include <stdlib.h>


size_t sizeArray = 0, line = 1;
//        lines chars       
char lines[50][100];

void printLines(){
  
  printf("\n");
}

void deleteLine(int ID, char lines[50][100]){

  for (size_t i = 0; i < line; i++){
    if(ID == i){
      //printf("Line %d says: %s", i, lines[i]);
      for(int j = i; j < line; j++){
        for(int k = 0; k<100; k++)
          lines[j][k] = lines[j+1][k];
      }
    }
  }
  
}

//Find char in file
void findChar(FILE *ptr){
  char tmp;
  char *file = (char*)calloc(sizeArray, sizeof(char));
  char buscando;
  int accum = 0, ID;
  char lines[50][100];


  //count the number of lines 
  while(fscanf(ptr, "%c", &tmp) != EOF){

    lines[line-1][sizeArray] = tmp;
    sizeArray++;

    if( tmp == '\n' ){
      //printf("Line %d says: %s", line-1, *(lines+line-1));
      line++;
      sizeArray = 0;
    }

  }
  
   for (size_t i = 0; i < line-1; i++)
  {
    printf("Line %d says: %s", i, *(lines+i));
  }

  printf("To delete a line, type the number of line you wish to delete: ");
  scanf("%d", &ID);
  deleteLine(ID,lines);
  line--;
   for (size_t i = 0; i < line-1; i++)
  {
    printf("Line %d says: %s", i, *(lines+i));
  }
  free(file);

}


void main(){
  FILE *ptr;
  ptr = fopen("input2.txt", "r+");

  if(ptr == NULL){
    printf("Archivo inexistente\n");
    exit(1);
  }

findChar(ptr);
fclose(ptr);
}
