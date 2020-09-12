#include <stdio.h>
#include <stdlib.h>


long decimalToBinary(int decimal){
  int binary = 128;
  long binaryvalue = 10000000, acc = 0;
  while(binary >= 1){
    if(decimal >= binary){
      acc+=binaryvalue;
      decimal-=binary;
    }
      binaryvalue/=10;
      binary/=2;
  }
  printf("binary is %ld\n", acc);
  return acc;
}

int calculateLength(long number){
  int length = 0;
  while(number >= 1){
    number /= 10;
    length++;
  }
  printf("%d\n", length);

  return length;
}
int find_lengthOfNumber(long binary){
  int length = 0;
  while(binary >= 1){
    binary /= 10;
    length++;
  }
  return length;
}

int oneComplement(int decimal){
  long binary = decimalToBinary(decimal);
  int length = find_lengthOfNumber(binary);
  
}


void main(){
  char option;
  int decimal;
  printf("There are three options\n Type a if you wish to have the one complement of that number\n Type s if you wish to have two's complement \n Type 3 if you wih to have the negative value\n");
  scanf("%c", &option);
  switch (option){
    case 'a':
        printf("Type the decimal you wish to calculate\n");
        scanf("%d", &decimal);
        int result = oneComplement(decimal);
        //printf("complement %d \n", oneComplement(decimal));
      break;
    case 2:
      break;
    case 3:
      break;
  }
}
