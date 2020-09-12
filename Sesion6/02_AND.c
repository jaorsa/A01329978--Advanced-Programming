#include <stdio.h>
#include <stdlib.h>

long decimalToBinary(int decimal){
  int binary = 128;
  long binaryvalue = 10000000, acc = 0;
  while(binary >= 1){
    //if(decimal == 0){}
    if(decimal >= binary){
      acc+=binaryvalue;
      decimal-=binary;
    }
      binaryvalue/=10;
      binary/=2;
  }
  printf("%ld\n", acc);
  return acc;
}

long find_number(int index){
  long binary = 10000000, number = 0;
  for (int i = 8; i >= 1; i--) {
    if (i == index){
      number += binary;
    }
    binary /= 10;
  }
  printf("%ld\n", number);
}

int find_lengthOfNumber(long binary){
  if(binary == 10000000) return 8;
  if(binary == 1000000) return 7;
  if(binary == 100000) return 6;
  if(binary == 10000) return 5;
  if(binary == 1000) return 4;
  if(binary == 100) return 3;
  if(binary == 10) return 2;
  if(binary == 1) return 1;
}

int binaryToNumber(long binary){
  int length = find_lengthOfNumber(binary);
  length -= 2;
  printf("%d\n", length);
  int decimal = 1;
  while(length >= 1){
    decimal = decimal * 2;
    length--;
  }
  return decimal;
}

void main(){
  int n;
  int bit;
  printf("Ingresa el numero: ");
  scanf("%d", &n);
  printf("Ingresa el bit: " );
  scanf("%d", &bit);

  long bit_binary = find_number(bit);
  int decimal = binaryToNumber(bit_binary);
  printf("%d\n", decimal);
  int and_op = n & decimal; printf("%d ", and_op); long and_op_binary = decimalToBinary(and_op);
}
