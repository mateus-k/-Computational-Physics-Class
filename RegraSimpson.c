#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

float integraX2(float dx, float xi, float xf);
float trapezio(float dx, float x0, float xf);

int main(void){
  
  float dx, xi ,xf, integral;
  
  
   printf("Digite os limites de integração na forma (xi, xf): ");
   scanf("%f, %f",&xi, &xf);
  
  printf("Digite o valor de delta x (a precisão): ");
  scanf("%f",&dx);
  

  
  printf("O valor da integral na Regra de Simson de x² em %f á %f é igual a: %f\n", xi, xf,  integraX2(dx, xi, xf));
  printf("O valor da integral na Regra do Trapezio de x² em %f á %f é igual a: %f\n", xi, xf, trapezio(dx, xi, xf));
  
  return 0;
}

float integraX2(float dx, float xi, float xf){

  int i, n;
  float x, y, Ai, integral;
  
  n = (xf - xi) / dx;
  
  integral=0.0;
  
  for (i=0; i<n; i++){
    x  = xi + dx * i;
    y  = x*x;         //<=========== é aqui que eu coloco a função externa!
    Ai = dx * y;
    integral += Ai;
  }
  
  return integral;
}

float trapezio(float dx, float x0, float xf){
  
  int i,n;
  float Ai, yi, xi, xiP, yiP, integral;
  n= (xf - xi) / dx;
  
  integral = 0.0;
  
  for (i=0; i<n; i++){
    xi   = x0 + i*dx;
    xiP = xi + dx;
    yi   = xi*xi;
    yiP = xiP*xiP;
  
   Ai = 0.5 * (yi +yiP)*dx;  
   integral += Ai;
  }
  
  return integral;
}