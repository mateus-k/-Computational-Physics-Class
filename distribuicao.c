#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  int i, n, intervalo, *distribuicao;
  float x, dx, xf, xi;
  FILE *arq1, *arq2;
  
  
  
  n=100000;
  xf=10.0;
  xi=-10.0;
  
  n = (xf - xi)/dx;
  
  distribuicao = malloc(n*sizeof(int));
  if  (distribuicao == NULL){
    printf("Erro na leitura!!");
    exit(1);
  }
  
  for (i=0; i<n; i++){
    distribuicao[i]=0;
  }
  
  arq1 = fopen("numAleatorios.dat","r");
  if (arq1 == NULL){
    printf("Erro na leitura!!");
    exit(1);
  }
  
  arq2 = fopen("distribuicao.dat","w");
  if (arq2 == NULL){
    printf("Erro na leitura!!");
    exit(1);
  }
  
  for (i=0; i<n; i++){
    fscanf(arq1, "%f", &x);
    intervalo = (x - xi)/dx;
    distribuicao[intervalo]=distribuicao[intervalo]+1;
  }
  
  for (i=0; i<n; i++){
    fprintf(arq2, "%d %d\n", i, distribuicao[i]);
    fprintf(arq2, "%d %d\n", i+1, distribuicao[i]);
  }
  
  fclose(arq1);
  fclose(arq2);
  
  return 0;
}
