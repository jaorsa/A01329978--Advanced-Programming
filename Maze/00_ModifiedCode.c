#include <stdio.h>
#include <stdlib.h>


typedef struct Players{
	int posX;
	int posY;
	int lastPosX;
	int lastPosY;
	
} Player;

void draw_maze(int posX, int posY, int * maze, int lastPosX, int lastPosY){
int row=0;
*(maze + lastPosX + lastPosY) = 0;
*(maze + posX + posY) = 2;
for(int col = 0; col < 10, row < 100; col++){
	printf("%d ", *(maze + col + row));
	if(col == 9){col=-1; row+=10; printf("\n");}
	}
}


void player_movements(char keyCode, int * maze, Player player){
switch(keyCode){
	case 'w':
	case '8':
	player.lastPosY = player.posY;
	player.posY -= 10;
	draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	break;
	case 'a':
	case '4':
	player.lastPosX = player.posX;
	player.posX -= 1;
	draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	break;
	case 'd':
	case '6':
	player.lastPosX = player.posX;
	player.posX += 1;
	draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	break;
	case 's':
	case '2':
	player.lastPosY = player.posY;
	player.posY += 10;
	draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
	break;
}
}



int * create_maze(int * maze){
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
void initGame(int * maze, int acc, Player player){


//
while(*(maze + 99) != 2){
//Draw the maze 
draw_maze(player.posX, player.posY, maze, player.lastPosX, player.lastPosY);
printf();


}

}

Player initPlayer(Player player){
	player.posX = 0;
	player.posY = 0;
	player->lastPosX = 0;
	player->lastPosY = 0;
	return player;
}

//Initialize all parameters
void main(){
int acc = 0;
int *ptmz;
ptmz = (int *) malloc(10 * 10 * sizeof(int));
ptmz = create_maze(ptmz);
//Create player 
Player player = initPlayer(player);

initGame(ptmz, acc, player);

free(ptmz);
}
