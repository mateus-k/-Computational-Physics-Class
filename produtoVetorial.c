#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
  
  int i , n;
  float *pV1, *pV2, *pV3;
 
  printf("Este programa faz o produto vetorial de dois vetores (VxV)\n\n");
  
  printf("Digite o número de elementos dos vetores: ");
  scanf("%d",&n);
  
  
  pV1 = malloc( n* sizeof(float) );
  if (pV1 == NULL){
     printf("Erro de alocação de memória\n");
     exit(EXIT_FAILURE);
  }
  
  pV2 = malloc( n* sizeof(float) );
  if (pV2 == NULL){
     printf("Erro de alocação de memória\n");
     exit(EXIT_FAILURE);
  }
  
  pV3 = malloc( n* sizeof(float) );
  if (pV3 == NULL){
     printf("Erro de alocação de memória\n");
     exit(EXIT_FAILURE);
  }
  
   for (i=0; i<n; i++){
     printf("Digite a componente %d do vetor 1: ",i);
     scanf("%f",&pV1[i]);
  }
  
  for (i=0; i<n; i++){
     printf("Digite a componente %d do vetor 2: ",i);
     scanf("%f",&pV2[i]);
  }
  
  pV3[0]= pV1[1]*pV2[2]-pV1[2]*pV1[1];
  pV3[1]= -(pV1[0]*pV2[2]-pV1[2]*pV1[0]);
  pV3[2]= pV1[0]*pV2[1]-pV1[1]*pV1[0];

  printf("As componentes do vetor resultantes é (%f ; %f ; %f)\n",pV3[0],pV3[1],pV3[2]);
  
  return 0;
}