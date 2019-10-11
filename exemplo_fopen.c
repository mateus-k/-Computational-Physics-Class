#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  int i, N; 
  float pi, theta0, thetaf, dtheta, theta, I;
  FILE *pfile;
  
  printf("Este é um exemplo que calcula a intensidade de luz quando passa por uma fenda.\n");
  printf("Ele calcula N pontos e armazena em um arquivo de nome ''fendaSimples''\n");
  
  printf("Digite o numero de pontos N: ");
  scanf("%d",&N);
  
  pfile = fopen("fendaSimples.dat","w");
  
  if (pfile == NULL){
    printf("erro na abertura do arquivo fendaSimplesdados.dat\n");
    exit(EXIT_FAILURE);
  }
  
  pi = 2*acos(0.0);
  theta0 = -8.0*pi;
  thetaf = 8.0*pi;  
  
  dtheta = (thetaf - theta0)/N;
  
  for (i = 0;  i <=N ; i++){
  
  theta = theta0 + dtheta*i;
  I = sin(theta/2)/(theta/2);
  I = I*I;
  
  fprintf(pfile,"%f %f\n",theta, I);
  }
  
  fclose(pfile);
  
  return 0;
}
