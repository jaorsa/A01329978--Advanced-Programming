#include <stdio.h>
#include <stdlib.h>

/*Filename: 01_static_library.h*/
char * readSize(char * size, FILE *fp){
  fscanf(fp, "%[^\n]", size);
  return size;
 }

char * readMaze(char * maze, FILE *fp){
  while(  fgets(maze, 100, fp ) != NULL )
    printf("%s\n", maze);
  return maze;
}

/*
void main(){
  FILE *fp;
  char size[N];
  char maze[SIZE];
  char **array;
  //Stack stack;
  //char n[N];
  if( (fp = fopen("maze.txt", "r")) == NULL ){
    printf("File not found\n");
    exit(1);
  }
  array = readFile(size, maze, fp);
  fclose(fp);
  //return stack;
}*/
