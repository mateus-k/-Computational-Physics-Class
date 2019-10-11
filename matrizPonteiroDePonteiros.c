#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
  
  int ncol, nlin, i, j, N;
  float **pM, traco;
 
  
  printf("Este programa faz o traço de uma matriz\n\n");
  printf("Digite o número de linhas da matriz: ");
  scanf("%d",&nlin);
  printf("A matriz deve ser quadrada por isso o número de linhas deve se o mesmo que o de colunas.\n\n");
  ncol = nlin;
  
  pM = malloc (nlin * sizeof(float *));
  if (pM == NULL){
     printf("Erro de alocação de memória!\n");
     exit(EXIT_FAILURE);
  }
     
  for (i = 0; i< ncol; i++){
    pM[i] = malloc ( nlin*sizeof(float));
     if (pM[i] == NULL){
       printf("Erro de alocação de memória!\n");
     exit(EXIT_FAILURE);
     }
  }   
  
  for (i=0; i<nlin; i++){
    for (j=0; j<ncol; j++){
      printf("Digite o elemento (%d, %d):",i,j);
      scanf("%f",&pM[i][j]);  
    }
  }
     
  traco=0.0;  
  for (i= 0; i<nlin; i++){  
    traco = traco + pM[i][i];
  }
  
  printf("\n");
  printf("O traço da matriz é: %f\n", traco);
    
  return 0;
}
