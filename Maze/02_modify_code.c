#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cell{
	int position_row = 0;
	int position_column = 0;
	int road = 0;
	bool visited = 0;
	struct cell *last;
};

void createMaze(){
	maze =
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
