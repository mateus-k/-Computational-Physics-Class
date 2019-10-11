#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void troca(int i1, int i2);

int main(void){
  
  int a, b, c;
  
  a=1;
  b=2;
   
  troca(a,b);
  
  printf("Fora da função:\n");
  printf("a = %d\n",a);
  printf("b = %d\n",b);
  
  return 0;
}

void troca(int i1, int i2){
    
  int temp;
  
  printf("Antes da troca:\n");
  printf("i1 = %d\n",i1);
  printf("i2 = %d\n",i2);
  
  temp = i1;
  i1      = i2;
  i2      = temp;
  
  printf("Depois da troca:\n");
  printf("i1 = %d\n",i1);
  printf("i2 = %d\n",i2);
}