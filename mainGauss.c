#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void triangularSuperior(int n, float **A, float *b);
substituicaoRetroativa(int n, float **a, float *b, float *x);

int main(void){
  
  int i, j, n;
  float **A, *b, *x;
  FILE *arq;
  
  arq = fopen("matriz.dat", "r");
  if (arq == NULL){
     printf("ERRO DE LEITURA NO ARQUIVO ''matriz.dat'' !!\n");
  exit(1);
     }
     
  fscanf(arq, "%d",&n); //Lê a dimensão da matriz na primeira linha
   
  A = malloc (n* sizeof(float *));
  if (A == NULL){
    printf("ERRO NA 1ª ALOCACAO DE MEMÓRIA DE ''A'' !!\n");
  exit(1);
  }
    
  
  for (i = 0; i<n; i++){
    A[i] = malloc (n* sizeof(float));
     if (A[i] == NULL){
     printf("ERRO NA 2ª ALOCACAO DE MEMÓRIA DE ''A'' !!\n");
  exit(1);
     }
  }
  
  b =malloc (n* sizeof(float));
  if (b == NULL){
     printf("ERRO NA ALOCACAO DE ''b'' !!\n");
  exit(1);
     }
    
  for (i=0; i<n; i++){  //Lê os elementos de matriz
    for (j=0; j<n; j++){
       fscanf(arq, "%f",&A[i][j]);
     }
     fscanf(arq, "%f", &b[i]);  //Lê os elementos do vetor coluna b
   }
  
  x =malloc (n* sizeof(float)); 
  if (x == NULL){
    printf("ERRO NA ALOCACAO DE ''x'' !!\n");
    exit(1);
  }
  
  triangularSuperior(n, A, b);
  substituicaoRetroativa(n, A, b, x);
  
   printf("A Matriz 'A'\n");
   for (i=0; i<n; i++){ //Imprimi a matriz A (note que já foi triangulazrizada)
     for (j=0; j<n; j++){
       printf("%f ", A[i][j]);
    }
    printf("\n");
   }
  
    printf("\n");
    printf("O vetor 'b'\n"); //Imprimir o vetor coluna b (depois da matriz A ser triangularizada)
    for (i =0; i<n; i++){
      printf("%f\n", b[i]);
    }
        
    printf("\n");
    printf("O vetor solucao\n"); //Imprimir o vetor x
    for (i =0; i<n; i++){
      printf("x[%d] = %f\n",i, x[i]);
    }
    
   fclose(arq);
   free(A);
   free(b);

   
   
   return 0;
}