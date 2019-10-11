#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
  
  int i, N;
  float A1, A2, T1, T2, y1, y2, w1, w2, yS;
  float pi, t, t0, tf, dt;
  FILE *p01;
  FILE *p02;
  FILE *pS;
  
  printf("Este programa lê dois valores de amplitude, dois valores de período e cria 200 pontos de duas ondas sinusoidais e a superposião delas\n");
  printf("Os pontos das das ondas são gravadas nos arquivos onda01.dat , onda02.dat e superposicao.dat.\n\n");
  
  printf("Digite o primeiro valor de amplitude: ");
  scanf("%f",&A1);
  
  printf("Digite o primero valor de período: ");
  scanf("%f",&T1);
  
  printf("Digite o segundo valor de ampitude: ");
  scanf("%f",&A2);
  
  printf("Digite o segundo valor de período: ");
  scanf("%f",&T1);
 
  p01 = fopen("onda01.dat","w");
  p02 = fopen("onda02.dat","w");
  pS = fopen("superposicao.dat","w");
  
  if (p01 == NULL){
    printf("erro na abertura do arquivo onda01.dat\n");
    exit(EXIT_FAILURE);
  }
  if (p02 == NULL){
    printf("erro na abertura do arquivo onda02.dat\n");
    exit(EXIT_FAILURE);
  }
  if (pS == NULL){
    printf("erro na abertura do superposicao.dat\n");
    exit(EXIT_FAILURE);
  }
    
  N = 200;
  pi = 2*acos(0.0);
  t0 = 0;
  tf = 200;
  
  w1 = 2*pi/T1;
  w2 = 2*pi/T2;
  
  dt = (tf - t0)/N;
  
  for (i = 0;  i <N ; i++){
    
    t = t0 + dt*i;
    
    y1 = A1*sin(w1*t);
    y2 = A2*sin(w2*t);
    
    yS = y1 +y2;
    
   fprintf(p01,"%f %f\n",t, y1);
   fprintf(p02,"%f %f\n",t, y2);
   fprintf(pS,"%f %f\n",t, yS);
  }
  
  fclose(p01);
  fclose(p02);
  fclose(pS);
  
  return 0;
}