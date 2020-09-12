#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void redrawMaze(bool * player){
	bool maze[10][10] = {
		0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
		1, 0, 1, 1, 1, 1, 0, 1, 1, 0,
		1, 0, 1, 0, 0, 0, 0, 1, 1, 0,
		1, 0, 0, 1, 0, 1, 1, 1, 1, 0,
		1, 1, 0, 1, 0, 1, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 1, 1, 0, 1, 0, 1, 0,
		0, 0, 0, 1, 0, 0, 1, 0, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 1, 0
		};
		
		int row = 0;
		for (int i = 1; i <= 10, row < 10; i++) {
			printf("%d ", maze[row][i-1]);

			if(i%10 == 0){printf("\n");row++;i = 0;}
		}
}

void initMaze(){
	printf("\n");
	bool maze[10][10] = {
		2, 0, 0, 0, 0, 1, 0, 1, 1, 0,
		1, 0, 1, 1, 1, 1, 0, 1, 1, 0,
		1, 0, 1, 0, 0, 0, 0, 1, 1, 0,
		1, 0, 0, 1, 0, 1, 1, 1, 1, 0,
		1, 1, 0, 1, 0, 1, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 1, 1, 0, 1, 0, 1, 0,
		0, 0, 0, 1, 0, 0, 1, 0, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 1, 0
		};
		int row = 0;
		for (int i = 1; i <= 10, row < 10; i++) {
			printf("%d ", maze[row][i-1]);
			if(i%10 == 0){printf("\n");row++;i = 0;}
		}
}



bool atEnd = false;
//Funcion para mover al jugador. Recibe el inicio del laberinto, el final, la posicion del jugador y adonde se mueve. Devuelve la direccion a moverse.
bool * moveIfPossible(bool * arrSt, bool * arrEn, bool * player, bool * nxtTile) {
	if(nxtTile>=arrSt && nxtTile<=arrEn && *nxtTile==false){
		printf("%x %x %x\n", *nxtTile - 11,*nxtTile - 10,*nxtTile - 9);
		printf("%x %x %x\n", *nxtTile - 1,*nxtTile,*nxtTile + 1);
		printf("%x %x %x\n", *nxtTile + 9,*nxtTile + 10,*nxtTile + 11);
		return nxtTile;
	}
	return player;
}

//Funcion recursiva para resolver automaticamente el laberinto. Recibe la posicion del jugador, el inicio del laberinto, el final y el acumulador de pasos. Devuelve el numero de pasos.
//Esta funcion puede cambiar como funciona, aun no esta terminada
int solveMaze(bool * player, bool * start, bool * end, int acc){
	bool *init = player;
	int initAcc = acc;
	if(player == end){
		atEnd = true;
		return acc;
	}

	player = moveIfPossible(start, end, player, player + 10*sizeof(bool));
	if (player != init && !atEnd){
		acc = solveMaze(player,start,end,acc+1);
	}

	if((player == init || initAcc<acc) && !atEnd){
		player == init;
		player = moveIfPossible(start, end, player, player + sizeof(bool));
		acc = solveMaze(player,start,end,acc+1);
	}

	if((player == init || initAcc<acc) && !atEnd){
		player == init;
		player = moveIfPossible(start, end, player, player - 10*sizeof(bool));
		acc = solveMaze(player,start,end,acc+1);
	}

	if((player == init || initAcc<acc) && !atEnd){
		player == init;
		player = moveIfPossible(start, end, player, player - sizeof(bool));
		acc = solveMaze(player,start,end,acc+1);
	}

	return acc;
}

int main() {
	initMaze();

	//Creacion del laberinto
	bool maze[10][10] = {
		{0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
		{1, 0, 1, 0, 0, 0, 0, 1, 1, 0},
		{1, 0, 0, 1, 0, 1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 1, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
		};
	//Declaracion de la posicion inicial del jugador, el inicio del laberinto, el final y una variable para  comparar el movimiento del jugador.
	bool *player = &maze[0][0], *start = &maze[0][0], *end = &maze[9][9], *initPos =  NULL;
	char key;
	int count = 0;

	while(player != end) {
		//Establecemos la posicion actual como inicial
		initPos = player;
		printf("Muevete con las W-A-S-D o 4-8-2-6\n");
		scanf("%c\n", &key);

		//Movimiento de acuerdo a la tecla presionadda
		switch(key) {
			case 'w':
			case '8':
				player = moveIfPossible(start, end, player, player - 10*sizeof(bool));
				redrawMaze(player);
			break;

			case 'a':
			case '4':
				player = moveIfPossible(start, end, player, player - sizeof(bool));
				redrawMaze(player);
			break;

			case 's':
			case '2':
				player = moveIfPossible(start, end, player, player + 10*sizeof(bool));
				redrawMaze(player);
			break;

			case 'd':
			case '6':
				player = moveIfPossible(start, end, player, player + sizeof(bool));
				redrawMaze(player);
			break;

			default:
				printf("Opcion invalida");
		}

		//Solo contara el paso si el jugador si se movio de la posicion inicial
		if(initPos != player)
			count++;
	}
	printf("Laberinto completado en: %d pasos\n", count);

	printf("La computadora lo resolvio en %d pasos\n", solveMaze(start,start,end,0));
	return 0;
}
