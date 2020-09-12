#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
  srand(time(0));
  int n = (rand() % (100-1+1)) + 1;
  int playerNumber = 0;
  int tries=0;
  int lastNumber;
  printf("random number is %d\n", n);
  while(playerNumber != n){
    printf("try to guess the number between 1 and 100 \n");
    scanf("%d", &playerNumber);
    if(lastNumber != playerNumber){
      tries++;
    }

    lastNumber = playerNumber;
  }
  printf("number of tries %d\n", tries);
}
