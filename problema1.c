#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  int i, N;
  float t, dt, t0, tf, theta, x, y;
  float r0, r, vb, omega;
  FILE *pfile1;
  
  printf("Este é um programa que calcula N pontos da trajetória do cachorro Bobi que foi buscar um jornal em uma plataforma que gira com velocidade ω\n\n");
  
  printf("Para calcular a trajetória é necessario digitar o valor da velocidade de Bobi em m/s: ");
  scanf("%f",&vb);
  
  printf("É preciso tambem a posição inicial de Bobi sobre a plataforma em m: ");
  scanf("%f",&r0);
  
  printf("Além disso é preciso a distância do ponto incial até a borda da plataforma, ou seja, o raio da plataforma tambem em m: ");
  scanf("%f",&r);
  
  printf("É claro que não é possivel saber a trajetória sem a velocidade  ω, por isso digite um valor em radianos/s: ");
  scanf("%f",&omega);
  
   //abrindo o arquivo de dados e acusando erro caso não for possivel abri-lo
   pfile1 = fopen("dados01.dat", "w");
   if (pfile1 == NULL){
   printf("erro na apertura do arquivo dados01.dat\n");
   exit(EXIT_FAILURE);
  }
  
  //com a equação r=r0 + vt (mas r0 = 0) vou encontrar o tempo o qual Bobi leva para chegar ao fim da plataforma de rairo r
  tf = r/vb;
  
  N = 100;
  t0 = 0;
  dt = (tf - t0)/N;
    
  for (i = 0; i<N; i++){
    
    t = t0 + dt*i;
  
    r = vb*t;
    theta = omega*t;
    
    x=r0 + r*cos(theta);
    y=r*sin(theta);
  
    fprintf(pfile1,"%f %f\n",x, y);
    printf("%f %f\n",x, y);
    
  }
  
  //fechando o arquivo
  fclose(pfile1);
  
  return 0;
}
