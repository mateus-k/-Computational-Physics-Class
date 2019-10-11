#include <stdio.h>
#include <math.h>

int main(void){
 
  double theta;
  double resultado;
  double pi;
  
  printf("Este programa pede ao usuário que escreva um ângulo θ (em graus) e em seguida imprima o resultado da operação cos² (θ)+sin² (θ)\n");
  printf("Por favor, digite o valor do angulo θ em graus: ");
  scanf("%lf",&theta);
  
  pi = 2*acos(0.0);
  
  //passando o angulo theta para radianos
  theta = theta*pi/180.0;
  
  resultado = cos(theta)*cos(theta) + sin(theta)*sin(theta);
  
  printf("O restultado da operação é: %lf\n",resultado);
  
  return 0;
}