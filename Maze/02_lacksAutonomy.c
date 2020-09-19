#include <stdio.h>
#include <stdlib.h>
/*Filename: 01_static_library.h*/
//#include "01_static_library.h"


typedef struct Players{
	int posX;
	int posY;
	int lastPosX;
	int lastPosY;
	int pasos;
} Player;

typedef	struct Cells{
	int posX;
	int posY;
	int visited;
} Cell;

/*				Función draw_maze
*		Recibe posicion del jugador en X y en Y, el laberinto y las posiciones anteriores del jugador antes de moverse
*		Imprime la posición del jugador en el laberinto
*/
void draw_maze(int posX, int posY, int * maze, int lastPosX, int lastPosY){
int row=0;
*(maze + posX + posY) = 2;
for(int col = 0; col < 10, row < 100; col++){
	printf("%d ", *(maze + col + row));
	if(col == 9){col=-1; row+=10; printf("\n");}
	}
}

/*				Función checkMovement
*		Recibe posicion del jugador en X y en Y, el laberinto y el tipo de movimiento a realizar
*		'd' significa down
*		'l' significa 'left'
*		'r' significa 'right'
*		'u' significa 'up'
*
*		Verifica que no se salga del laberinto y si no existe una pared que limite el movimiento
*		Regresa 0 si es verdadero o 1 si es falso
*
*/
int checkMovement(int posX, int posY, int * maze, char type){
	if(type == 'd'){
		return (posY < 90 && (*(maze + posX + posY+10) == 0))? 0:1;
	}
	if(type == 'l'){
		return (posX > 0  && (*(maze + posX-1 + posY) == 0))? 0:1;
	}
	if(type == 'r'){
		return (posX <= 8 && (*(maze + posX+1 + posY ) == 0))? 0:1;
	}
	if(type == 'u'){
		return (posY >= 10 && (*(maze + posX + posY-10) == 0))? 0:1;
	}
}


/*				Función player_movements
*		Recibe el codigo de llave, el laberinto y la estructura jugador
*		Comprueba que el movimiento es posible
*		Si es posible, actualiza la posición del jugador en X y en Y
*		Imprime el laverinto
*		Regresa el player con sus posiciones actualizadas
*
*/
Player player_movements(char keyCode, int * maze, Player player, char option ){
	printf("Posicion del jugador en X: %d\n", player.posX);
	printf("Posicion del jugador en Y: %d\n", player.posY);
switch(keyCode){
	case 'w':
	case '8':
	if(checkMovement(player.posX,player.posY, maze,  'u') == 0){
		player.pasos+=1;
		player.lastPosX = player.posX;
		player.lastPosY = player.posY;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = 0;}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = 1;}
		player.posY -= 10;
		printf("Ultima Posicion del jugador en X: %d\n", player.lastPosX);
		printf("Ultima Posicion del jugador en Y: %d\n", player.lastPosY);

		draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	}
	break;
	case 'a':
	case '4':
		if(checkMovement(player.posX,player.posY, maze,'l') == 0){
		player.pasos+=1;
		player.lastPosX = player.posX;
		player.lastPosY = player.posY;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = 0;}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = 1;}
		player.posX -= 1;
		printf("Ultima Posicion del jugador en X: %d\n", player.lastPosX);
		printf("Ultima Posicion del jugador en Y: %d\n", player.lastPosY);
		draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	}else{
		printf("Jugador no puede avanzar hacia la iz \n");}
	break;
	case 'd':
	case '6':
		if(checkMovement(player.posX,player.posY, maze,'r') == 0){
		player.pasos+=1;
		player.lastPosX = player.posX;
		player.lastPosY = player.posY;
		player.posX++;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = 0;}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = 1;}
		printf("Ultima Posicion del jugador en X: %d\n", player.lastPosX);
		printf("Ultima Posicion del jugador en Y: %d\n", player.lastPosY);
		draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	}else{
		printf("Jugador no puede avanzar hacia la derecha \n");}
	break;
	case 's':
	case '2':
		if(checkMovement(player.posX,player.posY, maze,'d') == 0){
		player.pasos+=1;
		player.lastPosX = player.posX;
		player.lastPosY = player.posY;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = 0;}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = 1;}
		//player.lastPosY = player.posY+1;
		player.posY += 10;
		//printf("Posicion del jugador en Y: %d\n", player.posY);
		printf("Ultima Posicion del jugador en X: %d\n", player.lastPosX);
		printf("Ultima Posicion del jugador en Y: %d\n", player.lastPosY);
		draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	}
	break;
	default:
	printf("Movimiento no permitido\n");
		break;
}
return player;
}

/*				Función create_maze
*		Recibe el array que va a ser llenado
*		Regresa el laberinto creado
*/

int * create_maze(int * maze){
/*maze = {
	0,0,0,0,0,0,0,0,1,0,
	1,0,1,0,1,0,1,0,1,0,
	1,1,0,0,1,0,0,1,0,0,
	0,1,1,0,0,1,0,1,1,0,
	0,1,1,1,0,1,0,0,1,0,
	0,0,0,0,0,0,0,1,1,1,
	1,0,1,1,0,0,1,0,0,0,
	1,0,0,1,1,1,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,
	1,1,1,1,0,0,0,1,1,0
};
*/


*(maze + 0 + 0) = 0;
*(maze + 1 + 0) = 0;
*(maze + 2 + 0) = 0;
*(maze + 3 + 0) = 0;
*(maze + 4 + 0) = 0;
*(maze + 5 + 0) = 0;
*(maze + 6 + 0) = 0;
*(maze + 7 + 0) = 0;
*(maze + 8 + 0) = 1;
*(maze + 9 + 0) = 0;

*(maze + 0 + 10) = 1;
*(maze + 1 + 10) = 0;
*(maze + 2 + 10) = 1;
*(maze + 3 + 10) = 0;
*(maze + 4 + 10) = 1;
*(maze + 5 + 10) = 0;
*(maze + 6 + 10) = 1;
*(maze + 7 + 10) = 0;
*(maze + 8 + 10) = 1;
*(maze + 9 + 10) = 0;

*(maze + 0 + 20) = 1;
*(maze + 1 + 20) = 1;
*(maze + 2 + 20) = 0;
*(maze + 3 + 20) = 0;
*(maze + 4 + 20) = 1;
*(maze + 5 + 20) = 0;
*(maze + 6 + 20) = 0;
*(maze + 7 + 20) = 1;
*(maze + 8 + 20) = 0;
*(maze + 9 + 20) = 0;

*(maze + 0 + 30) = 0;
*(maze + 1 + 30) = 1;
*(maze + 2 + 30) = 1;
*(maze + 3 + 30) = 0;
*(maze + 4 + 30) = 0;
*(maze + 5 + 30) = 1;
*(maze + 6 + 30) = 0;
*(maze + 7 + 30) = 1;
*(maze + 8 + 30) = 1;
*(maze + 9 + 30) = 0;

*(maze + 0 + 40) = 0;
*(maze + 1 + 40) = 1;
*(maze + 2 + 40) = 1;
*(maze + 3 + 40) = 1;
*(maze + 4 + 40) = 0;
*(maze + 5 + 40) = 1;
*(maze + 6 + 40) = 0;
*(maze + 7 + 40) = 0;
*(maze + 8 + 40) = 1;
*(maze + 9 + 40) = 0;

*(maze + 0 + 50) = 0;
*(maze + 1 + 50) = 0;
*(maze + 2 + 50) = 0;
*(maze + 3 + 50) = 0;
*(maze + 4 + 50) = 0;
*(maze + 5 + 50) = 0;
*(maze + 6 + 50) = 0;
*(maze + 7 + 50) = 1;
*(maze + 8 + 50) = 1;
*(maze + 9 + 50) = 1;

*(maze + 0 + 60) = 1;
*(maze + 1 + 60) = 0;
*(maze + 2 + 60) = 1;
*(maze + 3 + 60) = 1;
*(maze + 4 + 60) = 0;
*(maze + 5 + 60) = 0;
*(maze + 6 + 60) = 1;
*(maze + 7 + 60) = 0;
*(maze + 8 + 60) = 0;
*(maze + 9 + 60) = 0;

*(maze + 0 + 70) = 1;
*(maze + 1 + 70) = 0;
*(maze + 2 + 70) = 0;
*(maze + 3 + 70) = 1;
*(maze + 4 + 70) = 1;
*(maze + 5 + 70) = 1;
*(maze + 6 + 70) = 0;
*(maze + 7 + 70) = 0;
*(maze + 8 + 70) = 0;
*(maze + 9 + 70) = 0;

*(maze + 0 + 80) = 0;
*(maze + 1 + 80) = 0;
*(maze + 2 + 80) = 0;
*(maze + 3 + 80) = 0;
*(maze + 4 + 80) = 0;
*(maze + 5 + 80) = 1;
*(maze + 6 + 80) = 0;
*(maze + 7 + 80) = 0;
*(maze + 8 + 80) = 1;
*(maze + 9 + 80) = 0;

*(maze + 0 + 90) = 1;
*(maze + 1 + 90) = 1;
*(maze + 2 + 90) = 1;
*(maze + 3 + 90) = 1;
*(maze + 4 + 90) = 0;
*(maze + 5 + 90) = 0;
*(maze + 6 + 90) = 0;
*(maze + 7 + 90) = 1;
*(maze + 8 + 90) = 1;
*(maze + 9 + 90) = 0;

return maze;
}

//Initialize game
void initGame(int * maze, Player player){
char key;
//Draw the maze
draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
while(*(maze + 99) != 2){
	printf("Muevete con A-W-S-D o con 4-8-6-2\n" );
	scanf(" %c", &key);
	player = player_movements(key, maze, player, 'p');
}
printf("el jugador tuvo %d\n", player.pasos);
}

Cell initcell(Cell cell){
	cell.posX = 0;
	cell.posY = 0;
	cell.visited = 1;
	return cell;
}

/*DEpth First Search Algorithm */
/*
*	Up
* Right
*	Down
*	Left
*/
void solveGame(int * maze, Player player, Cell * stack){
	int mov;
	Cell initial;
	//Create initialCell
	initial = initcell(initial);
*(stack + 0) = initial;
	while(*(maze + 99) != 2){


	}

}

Player initPlayer(Player player){
	player.posX = 0;
	player.posY = 0;
	player.lastPosX = 0;
	player.lastPosY = 0;
	player.pasos=0;
	return player;
}

char * readSize(char * size, FILE *fp){
  fscanf(fp, "%[^\n]", size);
  return size;
 }

char * readMaze(char * maze, FILE *fp){
  while(  fgets(maze, 100, fp ) != NULL )
    printf("%s\n", maze);
  return maze;
}


//Initialize all parameters
void main(){
FILE *fp;
FILE *fpp;
char *text;
char *mace;

if( (fp = fopen("maze.txt", "r")) == NULL ){
	printf("File not found\n");
	exit(1);
}

//size = readSize(size, fp);
text = readMaze(text, fp);

int *ptmz;
ptmz = (int *) malloc(10 * 10 * sizeof(int));
ptmz = create_maze(ptmz);
//Create player
Player player = initPlayer(player);
Cell *stack;
int opcion = 0;
printf("Tienes dos opciones:\n Ingresa 1 si deseas jugar \n Ingresa 2 si deseas que el laberinto se resuelva solo\n");
scanf(" %d", &opcion);
if(opcion == 1){initGame(ptmz, player);}
if(opcion == 2){}
free(ptmz);
//fclose(fp);
}
