#include <stdio.h>
#include <stdlib.h>

/*Filename: 01_static_library.h*/
char * readSize(char * size, FILE *fp){
  fscanf(fp, "%[^\n]", size);
  return size;
 }

char * readMaze(char * maze, FILE *fp){
  //int count = fread(maze, sizeof(char), 200, fp);
  char c;
  int i = 0;
  while(fscanf(fp, "%c", &c) != EOF){
    *(maze + i) = c;
    printf("%c", c);
    i++;
  }

  return maze;
}

/*
void main(){

  FILE *fp;
  if( (fp = fopen("maze.txt", "r")) == NULL ){
  	printf("File not found\n");
  	exit(1);
  }

  char *mace = (char *)malloc(100);
  char *size = (char *)malloc(4);

  size = readSize(size, fp);
  mace = readMaze(mace, fp);
}*/
