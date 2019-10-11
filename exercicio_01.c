#include <stdio.h>
#include <math.h>

int main(void){
  
  float num, resultado;
  
  printf("Este programa calcula a raiz quarta de um numero. Digite o numero: ");
  scanf("%f",&num);
  
  resultado = sqrt(sqrt(num));
  
  printf("A raiz quarta de %f eh: %f\n",num,resultado);
  
  return 0;
}
  
