#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
  int n, i;
  float *pV, modulo; 
  
  printf("Este programa faz o módulo de um vetor.\n\n");
  printf("Digite o número de elementos do vetor: ");
  scanf("%d",&n);
  
  pV = malloc( n* sizeof(float) );
  if (pV == NULL){
     printf("Erro de alocação de memória\n");
     exit(EXIT_FAILURE);
  }
  
  for (i=0; i<n; i++){
     printf("Digite a componente %d do vetor: ",i);
     scanf("%f",&pV[i]);
  }
  
  modulo=0.0;
  for (i=0; i<n; i++){
     modulo = modulo +pV[i]*pV[i];
  }
    
  modulo = sqrt(modulo);
  printf("O modulo do vetor digitado é %f\n", modulo);
    
  
  return 0;
}
