#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){

  int i, N;
  float x, y, x0, xf, T, pi, dx;
  
  printf("Este é um exemplo de um programa que calcula y e x da equação y=sen(x) para N ponto\n\n");
  
  pi = acos(-1.0);
  T = 2.0*pi;
  x0 = 0;
  xf = 2.0*T;
  
  printf("Digite o numero de pontos N: ");
  scanf("%d",&N);

  
  dx = (xf - x0)/(N - 0);
  
  printf("Os pontos são (x ; y)\n");
 
  for (i = 0; i<N; i++){
    x = x0 + dx*i;
    y=sin(x);
    

    printf("Os pontos são (%f ; %f)\n",y,x);
  }
  
  return 0;
 }
