#include <stdio.h>
#include <math.h>

int main(void){
  double sen1, sen2, sen3, asen1, asen2, asen3, x1 = 0.0314, x2 = 0.314, x3 = 3.14;
  
  printf("Para pequenos angulos o seno é aproximado por uma serie. Este é um exercicio para a verificar o seno de 3 valores de x\n");
  printf("Os valores do exercicio são: %f ; %f ; %f\n",x1,x2,x3);
   
  asen1 = x1 - pow(x1,3)/6 + pow(x1,5)/120;
  sen1 = sin(x1);
  
  asen2 =x2 - pow(x2,3)/6 + pow(x2,5)/120;
 sen2 = sin(x2);
  
  asen3 =x3 - pow(x3,3)/6 + pow(x3,5)/120;
  sen3 = sin(x3);
  
  printf("O seno aproximado de %f eh %f e a função seno retorna %f\n",x1,asen1,sen1);
  printf("O seno aproximado de %f eh %f e a função seno retorna %f\n",x2,asen2,sen2);
  printf("O seno aproximado de %f eh %f e a função seno retorna %f\n",x3,asen3,sen3);
  
  return 0;
}