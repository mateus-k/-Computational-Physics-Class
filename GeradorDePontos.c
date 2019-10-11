#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void){
  
  int N, i;

  float x, y, dx, x0, xf;
  FILE *dados1, *dados2;
  
	x0=-34; xf=0; N=500;
	
  dx = (xf - x0)/N ; 
 
  dados1 = fopen("Deut1.dat", "w");  
  dados2 = fopen("Deut2.dat", "w");  
  if (dados1 == NULL || dados2 == NULL ){
      printf("erro na abertura do arquivo dados.dat\n");
      exit(EXIT_FAILURE);
  }
  
  for (i = 0; i<N; i++){
      x = x0 + dx*i;
      y = 0.155*sqrt(x+35)/tan(0.155*2.1*sqrt(x+35));
      fprintf(dados1,"%f %f\n",x,y);
    }

  for (i = 0; i<N; i++){
      x = x0 + dx*i;
      y = -0.155*sqrt(-x);
      fprintf(dados2,"%f %f\n",x,y);
    }
    
    printf("dados gerados\n");
  
  fclose(dados1); fclose(dados2);
  
}


