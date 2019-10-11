#include <stdio.h>
#include <math.h>

int main(void){
  
  int i;
  float f;
  double d;
  
  int *pi;
  float *pf;
  double *pd;
  
  pi = &i;
  
  printf("O ponteiro pi esta em %p\n", pi);
  
  printf("O int esta na posição %p\n",&i);
  printf("O float esta em %p\n",&f);
  printf("O double esta em %p\n",&d);
  
  printf("O tamanho do int é    %d\n",sizeof(i));
  printf("O tamanho do float é  %d\n",sizeof(f));
  printf("O tamanho do double é %d\n",sizeof(d));
  
  return 0;
}