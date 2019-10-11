#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void baskara(int *ehComplexa, float a, float b, float c, float *r1, float *i1, float *r2, float *i2);

//=======================================================

int main(void){

  int teste;
  float a, b, c, r1, r2, i1, i2;
  
  
 printf("Digite o valor de a, b e c da equação ax² + bx + c = 0 na forma a, b, c: ");
 scanf("%f, %f, %f",&a, &b, &c);

  baskara(&teste, a, b , c, &r1, &i1, &r2, &i2);
  if (teste == 0){
    printf("A solução não é complexa\n");
    printf("A solução 1 é: %f\n", r1);
    printf("A solução 1 é: %f\n", r2);
  }else {
    printf("A solução é complexa\n");
    printf("A solução 1 é: %f%+fi\n", r1, i1);
    printf("A solução 1 é: %f%+fi\n", r2, i2);
  }
  
  return 0;
}

//===========================================================
void baskara(int *ehComplexa, float a, float b, float c, float *r1, float *i1, float *r2, float *i2){

  //Se for complexa ehComplexa = 1
  float x1, x2, delta;
  
  delta = (b*b - 4.0*a*c);
  
  if (delta >= 0.0){
    *ehComplexa = 0; //nao é complexa
    *r1 = (-b + sqrt(delta) ) / (2.0*a);
    *r2 = (-b  - sqrt(delta) )  / (2.0*a);
  }else {
    *ehComplexa = 1; //É complexa
    *r1 = (-b) / (2.0*a); 
    *i1 = sqrt(-delta) / (2.0*a);
    *r2 = *r1; 
    *i2 = - (*i1); 
  }
}