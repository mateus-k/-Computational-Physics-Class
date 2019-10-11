#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




//programa principal
  
  float quadratica(float x);
  void geradorDados(float (*funcao)(float x), int nDados, float x0, float xf);
  
int main(void){
  
  int N;
  float x0, xf;
  
  printf("Digite o x incial e o x final na forma x0,xf: ");
  scanf("%f,%f",&x0, &xf);
  
  printf("Digite a quantidade de pontos");
  scanf("%f",&N);
  
  geradorDados(quadratica, N, x0, xf);
  
  return 0;
}
  
  //FUNÇÃO DE FUNCAO
  void geradorDados(float (*funcao)(float x), int nDados, float x0, float xf){
    
    int i;
    float dx, x, y;
    FILE *arq;
    
    dx = (xf - x0)/nDados;
    
    arq = fopen("dados.dat", "w");
    if (arq == NULL){
      printf("Erro na criação de dados!!");
      exit(EXIT_FAILURE);
    }
    
    for (i=0; i<nDados; i++){
      x =x0 + dx*i;
      y = (*funcao)(x);
      
      fprintf(arq,"%f %f\n",x, y);
    }
    
    fclose(arq);
  }
  
  //FUNCAO EXTERNA O Y DO MEU PROGRAMA
  float quadratica(float x){
    
    return x*x;
  }
  