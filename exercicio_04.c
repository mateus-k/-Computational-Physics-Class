#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  int i , x, t;
  float p, a = 2.4;
  
  printf("Este é um programa que calcula a probabilidade um chamada individual que tenha uma duração de t minutos.\n");
  printf("Para isso utiliza a equação P(<t)=1.0 - exp(-t/a), onde a neste caso é a = 2.4.\n\n");
  
  printf("Digite o valor de t em minutos: ");
  scanf("%d",&t);
  
  for (i=0;  i<=t; i = i + 1){
  
    p = 1.0 - exp(-i/a);
   
  printf("A probabilidade para t = %d min é: %f\n",i,p);

  }
  
  return 0;
}
