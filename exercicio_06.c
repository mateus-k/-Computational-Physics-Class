#include <stdio.h>
#include <math.h>

int main(void){
 
  double t = 275;
  double N0 = 250;
  double N;
  
  printf("Um modelo que calcula a quantidade matéria de um material radioativo depois de t anos está dado pela equação :\n");
  printf("N = N0 exp(-0.00012t)\n");
  
  N = N0*exp(-0.00012*t);
  
  printf("O restante do material radiativo que no início tinha %f gramas depois de %f anos é: %f gramas\n",N0,t,N);
  
  return 0;
}