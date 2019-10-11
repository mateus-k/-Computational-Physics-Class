#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  int i, j, k, nlinA, nlinB, ncolA, ncolB;
  float a[2][3], b[3][4], c[2][4];
  FILE *arq;
  
  nlinA=2; nlinB=3;
  ncolA=3; ncolB=4
  
  arq = fopen("matriz1.dat", "r");
  if (arq == NULL){
    printf("erro na abertura do arquivo matriz1.dat\n");
    exit(EXIT_FAILURE);
  }
  
  for (i=0; i<nlinA; i++){
     for (j=0; j<ncolA; j++){
        fscanf(arq, "%f", &a[i][j]);
     }
  }
  
   for (i=0; i<nlinB; i++){
     for (j=0; j<ncolB; j++){
        fscanf(arq, "%f", &b[i][j]);
     }
  }
  
  fclose(arq);
    
  for (i=0; i<nlinA; i++){
     for (j=0; j<ncolB; j++){
       c[i][j]=0; 
       for (k=0; k<nlinB; k++);{
       c[i][j] = c[i][j] + a[i][k]*b[k][j];
	}
     }
  }
  
  //imprimindo o resultado
  for (i=0; i<nlinA; i++){
     for (j=0; j<ncolB; j++){
     printf("%f", c[i][j]); 
     }
     printf("\n");
  } 
  
     
  return 0;
}