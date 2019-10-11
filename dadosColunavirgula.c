#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void){
  
  int n;
  float x, y;
  FILE * pontos;
  
  pontos = fopen("pontos01.dat", "r");
  if (pontos == NULL){
    printf("erro na apertura do arquivo pontos01.dat\n");
    exit(EXIT_FAILURE);
  }
  
  //nota-se que só foi colocado uma virgula
  n = 0;
  while(true){
    fscanf(pontos,"%f , %f", &x, &y);
    if (feof(pontos)) break;
    n = n +1; 
    printf("ponto %d = (%f ; %f)\n", n,x,y);
  }
  
  fclose(pontos);
  
  return 0;
}