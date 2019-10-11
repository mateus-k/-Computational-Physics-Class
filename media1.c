#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void){
  
  int i, n;
  float soma, media, nota;
  FILE *dat;
  
  dat = fopen("resulProva.dat", "r");  
  if (dat == NULL){
    printf("erro na apertura do arquivo resulProva.dat\n");
    exit(EXIT_FAILURE);
  }
  
  n=0;
  while (true){
    fscanf(dat,"%f", &nota);
    if (feof(dat)){
      break;
    }
    soma = soma + nota;
    n = n + 1;  
  }
  
  printf("O número de linhas é = %d\n",n);
  
  if(n > 0){
    media = soma/n;
    printf("A media do semestre é: %f\n",media);
  } 
    
  fclose(dat);
  
  return 0;
}