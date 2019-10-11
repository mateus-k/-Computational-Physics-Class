#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void criarGrafico(float N, float x0, float tf, float x, float y){
  
  float dx;
  FILE *dados;
  
  dx = (xf - x0)/N ;
 
  dados = fopen("dados.dat", "w");
  if (dados == NULL){
      printf("erro na abertura do arquivo dados.dat\n");
      exit(EXIT_FAILURE);
  }
  
  for (i = 0; i<N; i++){
      x = x0 + dx*i;
      y = tan(x*2.1)
      fprintf(dados, "%f  %f\n",x,y);
    }
  
  fclose(dados);
  
}


