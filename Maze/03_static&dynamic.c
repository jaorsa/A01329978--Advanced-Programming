#include <stdio.h>
#include <stdlib.h>
/*Filename: 01_static_library.h*/
#include "01_static_library.h"


typedef struct Players{
	int posX;
	int posY;
	int lastPosX;
	int lastPosY;
	int pasos;
} Player;

/*				Función draw_maze
*		Recibe posicion del jugador en X y en Y, el laberinto y las posiciones anteriores del jugador antes de moverse
*		Imprime la posición del jugador en el laberinto
*/
void draw_maze(int posX, int posY, char * maze, int lastPosX, int lastPosY){
int row=0;
*(maze + posX + posY) = '1';
for(int col = 0; col < 10, row < 200; col++){
	printf("%c", *(maze + col + row));
	if(col == 19){col=-1; row+=20;} //printf("\n");}
	}
	printf("\n");
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
int checkMovement(int posX, int posY, char * maze, char type){
	if(type == 'd'){
		return (posY < 190 && ( *(maze + posX + posY+20) == '_' || *(maze + posX + posY+20) == '2') )? 0:1;
	}
	if(type == 'l'){
		return (posX > 1  && (*(maze + posX-2 + posY) == '_'))? 0:1;
	}
	if(type == 'r'){
		return (posX <= 18 && (*(maze + posX+2 + posY ) == '_'))? 0:1;
	}
	if(type == 'u'){
		return (posY >= 20 && (*(maze + posX + posY-20) == '_'))? 0:1;
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
Player player_movements(char keyCode, char * maze, Player player, char option ){
	printf("Posicion del jugador en X: %d\n", player.posX);
	printf("Posicion del jugador en Y: %d\n", player.posY);
switch(keyCode){
	case 'w':
	case '8':
	if(checkMovement(player.posX,player.posY, maze,  'u') == 0){
		player.pasos+=1;
		player.lastPosX = player.posX;
		player.lastPosY = player.posY;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = '_';}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = '*';}
		player.posY -= 20;
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
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = '_';}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = '*';}
		player.posX -= 2;
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
		player.posX+=2;
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = '_';}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = '*';}
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
		if(option == 'p'){*(maze + player.lastPosX + player.lastPosY) = '_';}
		if(option == 's'){*(maze + player.lastPosX + player.lastPosY) = '*';}
		//player.lastPosY = player.posY+1;
		player.posY += 20;
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

//Initialize game
void initGame(char * maze, Player player){
char key;
//Draw the maze
draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
while(*(maze + 199) != '1'){
	printf("Muevete con A-W-S-D o con 4-8-6-2\n" );
	scanf(" %c", &key);
	player = player_movements(key, maze, player, 'p');
}
printf("el jugador tuvo %d pasos \n", player.pasos);
}

/* movimientos: abajo, derecha, arriba, izquierda*/
int solveGame(char * maze, Player player, int move){
	char movements[] = {'d', 'r', 'u', 'l'};
	char movements1[] = {'s', 'd', 'w', 'a'};

	for(int i = 0; i < 4; i++){
		int pos = rand()%4;
		int desp = rand()%3 + 1;
		char temp = movements[pos];
		movements[pos] = movements[(pos+desp)%4];
		movements[(pos+desp)%4] = temp;

		temp = movements1[pos];
		movements1[pos] = movements1[(pos+desp)%4];
		movements1[(pos+desp)%4] = temp;
	}

	if(*(maze + 199) != '1'){
		for(int i = 0; i < 4; i++){
			if(checkMovement(player.posX, player.posY, maze, movements[move%4]) == 0){
				player = player_movements(movements1[move%4], maze, player, 'p');

				if(solveGame(maze, player, move) == 0){
					player = player_movements(movements1[(move+2)%4], maze, player, 'p');

					move++;
				}
				else{
					return 1;
				}
			}
			else{
				if(move == 3){
					return 0;
				}
				else{
					move++;
				}
			}
		}
	}
	printf("el jugador tuvo %d pasos\n", player.pasos);
	exit(1);
	return 0;
}


Player initPlayer(Player player){
	player.posX = 1;
	player.posY = 0;
	player.lastPosX = 0;
	player.lastPosY = 0;
	player.pasos=0;
	return player;
}

//Initialize all parameters
void main(){
FILE *fp;

int tam;
char *size = (char *)malloc(4);
char *mace = (char *)malloc(200); //

if( (fp = fopen("maze.txt", "r")) == NULL ){
	printf("File not found\n");
	exit(1);
}

size = readSize(size, fp);
tam = atoi(size);
printf("%d\n", tam);
mace = readMaze(mace, fp);

//Create player
Player player = initPlayer(player);

int opcion = 0;
printf("Tienes dos opciones:\n Ingresa 1 si deseas jugar \n Ingresa 2 si deseas que el laberinto se resuelva solo\n");
scanf(" %d", &opcion);
if(opcion == 1){initGame(mace, player);}
if(opcion == 2){solveGame(mace, player, 0);}
}
