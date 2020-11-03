#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void main(){
    struct dirent *files;
    DIR *dir = opendir(".");
    if(dir == NULL){printf("Directory could not be opened"); exit(1);}
    while((files = readdir(dir))!= NULL){
        char *args[] = {files->d_name, NULL};
        execv("./02_copy_file.c", args);     
    }
    closedir(dir);
}