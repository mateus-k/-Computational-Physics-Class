#include <stdio.h>
#include <math.h>

int main(void){

  int i1, i2, i3;
  float f;
  double d;
 
  printf("Digite um inteiro com espaços: ");
  scanf("%d %d %d",&i1, &i2, &i3);
  
  printf("O inteiro digitado é %d\n", i1);
  printf("O inteiro digitado é %d\n", i2);
  printf("O inteiro digitado é %d\n", i3);
  
  
  printf("Digite um inteiro com virgulas: ");
  scanf("%d, %d, %d",&i1, &i2, &i3);
  
  printf("O inteiro digitado é %d\n", i1);
  printf("O inteiro digitado é %d\n", i2);
  printf("O inteiro digitado é %d\n", i3);
  
  
  return 0;
}