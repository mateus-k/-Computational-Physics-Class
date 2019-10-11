#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  int i, n;
  float a[2][3],  c[3];
  FILE *arq;
  
  n=3;
  //lendo arquivos 
  arq = fopen("vetores01.dat", "r");
  if (arq == NULL){
    printf("erro na apertura do arquivo vetores01.dat\n");
    exit(EXIT_FAILURE);
  }

  fscanf(arq, "%f %f %f", &a[0][0], &a[0][1], &a[0][2]);
  fscanf(arq, "%f %f %f", &a[1][0], &a[1][1], &a[1][2]);
  
  fclose(arq);
  
//somando vetors
for (i = 0; i<n;  i++){
  c[i] = a[0][i] + a[1][i];
}

for (i = 0; i<n; i++){
 printf("c[%d] = %f\n",i,c[i]);
}


  return 0;
}
