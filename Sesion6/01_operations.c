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

int calculateLength(long number){
  int length = 0;
  while(number >= 1){
    number /= 10;
    length++;
  }
  printf("%d\n", length);

  return length;
}

int * numberToArray(long number, int length){
  int * array = calloc(length, sizeof(int));
  for (int i = 0; i < length; i++) {
    array[i] = number%10;
    number /= 10;
  }
  return array;
}

void main(){
  int x = 54;
  int y = 17;
  //long binaryX = decimalToBinary(x);
  //int lengthX = calculateLength(binaryX);
  //long binaryY = decimalToBinary(y);
  //int lengthY = calculateLength(binaryY);
  //int * arrayX = numberToArray(binaryX, lengthX);
  //int * arrayY = numberToArray(binaryY, lengthY);
  int and_op = x & y; printf("%d ", and_op); long and_op_binary = decimalToBinary(and_op);
  int or_op = x | y; printf("%d ", or_op); long or_op_binary = decimalToBinary(or_op);
  int xor_op = x ^ y; printf("%d ", xor_op); long xor_op_binary = decimalToBinary(xor_op);
  int neg_op = ~y; printf("%d ", neg_op); long neg_op_binary = decimalToBinary( neg_op );
  int left_shift_op = x << 2;printf("%d ", left_shift_op); long left_shift_op_binary = decimalToBinary( left_shift_op );
  int right_shift_op = y >> 2;printf("%d ", right_shift_op); long right_shift_op_binary = decimalToBinary( right_shift_op );
}
