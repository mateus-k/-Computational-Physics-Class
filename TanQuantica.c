#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){

  int i, N;
  float  x0, xf, pi, dx;
  float R=2.1E-15/*m*/, c=299792458/*m/s*/, h=6.582119E-10/*MeV.s*/, mp=938.272046E6/*eV*/, mn=939.565378E6/*eV*/, V0=-35/*MeV*/, x, y, b, m;
  FILE *arq;
 
  pi = acos(-1.0);
  x0 = 0;
  xf = 4.0*pi;
  
  printf("Digite o numero de pontos N: ");
  scanf("%d",&N);

  arq = fopen("TanQuantica.dat", "w");
  
  m=mp*mn/(mp+mn);
  m=m/c;
  b=sqrt(2*m*R)/h;

  
  dx = (xf - x0)/(N - 0);
   
  
  for (i = 0; i<N; i++){
    x = x0 + dx*i;
    y=tan(b*sqrt(x+V0));
    
    fprintf(arq, "%f %f\n",y,x);
  }
  
  return 0;
 }
