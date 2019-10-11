#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){

  int i, N;
  float a, e, pi, theta0, thetaf, dtheta, theta, r, x, y;
  
  printf("Este é um exemplo que imprime pontos de uma elipse com origem em um dos focos de semi-eixo a e excentricidade e.\n\n");
  printf("Digite a excentricidade e (entre 0 e 1.0): ");
  scanf("%f",&e);
  printf("Digite o semi-eixo a: ");
  scanf("%f",&a);
  
  pi = acos(-1.0);
  theta0 = 0;
  thetaf = 2*pi;
   
  printf("Digite o numero de pontos N: ");
  scanf("%d",&N);
  
  dtheta = (thetaf - theta0)/(N - 0);
  
  printf("Os pontos são (x ; y)\n");
  
   for (i = 0; i<N; i++){
    theta = theta0 + dtheta*i;
   
    r = a*(1- e*e)/(1 + e*cos(theta));
  
    x = 1 - sqrt(1 - (e/a)*(e/a)) + r*cos(theta);
    y = r*sin(theta);
    
    printf("Os pontos são (%f ; %f)\n",x,y); 
   }
  
  return 0;
}