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
  printf("The result in binary is %ld\n", acc);
  return acc;
}

void main(){
  int x = 12;    // 0000000000000101
  int y = -12;   // 1111111111111101
  int not_y = ~y  + 1;   // 0000000000000010
  printf("not y is %d\n",not_y );
  int add_op = not_y & x; printf("The result in decimal is %d\n", add_op);
  long binary = decimalToBinary(add_op);
}
