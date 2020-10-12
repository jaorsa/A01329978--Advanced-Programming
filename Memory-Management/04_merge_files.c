#include <stdio.h>
#include <stdlib.h>

size_t sizeArray = 1;

void main(){
    FILE *ptr, *ptr2, *merge;
    ptr = fopen("input.txt", "r+");
    ptr2 = fopen("input2.txt", "r+");
    merge = fopen("newinput.txt", "w+");
    char tmp;
    char *file = (char*)calloc(sizeArray, sizeof(char));

    if(ptr == NULL || ptr2 == NULL){
    printf("Archivo inexistente\n");
    exit(1);
  }
 
    while(fscanf(ptr, "%c", &tmp) != EOF){
        *(file + sizeArray-1) = tmp;
        sizeArray++;
        file = (char*)realloc(file, sizeArray * sizeof(char));
    }
        fwrite(file, sizeArray, sizeof(file), merge);

        sizeArray = 1;
        file = (char*)realloc(file, sizeArray * sizeof(char));

    while(fscanf(ptr2, "%c", &tmp) != EOF){
        *(file + sizeArray-1) = tmp;
        sizeArray++;
        file = (char*)realloc(file, sizeArray * sizeof(char));
    }
    fwrite(file, sizeArray, sizeof(file), merge);

    fclose(ptr);
    fclose(ptr2);
    fclose(merge);
}