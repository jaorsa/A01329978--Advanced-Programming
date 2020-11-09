/*  
    Código de la función 1
    inopen(const char *pathname, const char *flags)
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct EntSal{
int level; // el buffer está vacio o está lleno
int bsize; // tamaño de la data  
char fd; // File Descriptor
char* buffer; // Data 
int *offset; // Byte pointer
}EntSal;

void search(const char *name){
    DIR *dir;
    struct dirent *dirEnt;
}

void readchar(){




}


void inopen(const char *name, char *flags){ 
int temp;
    //read flag
    if (strcmp(flags,"read") == 0){
       int file = open(name, O_RDONLY);
       if (file == -1){printf("Cannot open file %s\n", name);}
       
    }
    // write flag
    if (strcmp(flags,"write") == 0){
       int file = open(name, O_WRONLY);
       if (file == -1){printf("Cannot open file %s\n", name);}
    }
    //extend
    if (strcmp(flags,"extend") == 0){
       int file = open(name, O_RDWR);
       if (file == -1){printf("Cannot open file %s\n", name);}
       int byte = lseek(file, 0, SEEK_END);
       printf("byte %d", byte);
       
    }
}
 
int main(){
char name[30];
char flag[7];
    scanf("%s %s", &name, &flag);
    inopen(name, flag);
return 0;
}   
    

