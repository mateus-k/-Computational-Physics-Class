#include <stdio.h>
#include <math.h>

int main(void){
  
  double v, teta, h;
  
  printf("Este programa calcula máxima altura que uma bola atinge quando é jogada para cima com uma velocidade inicial v (em m/s) e um angulo teta em relação à horizontal\n");
  printf("Digite o valor da velocidade v em m/s: ");
  scanf("%lf",&v);
  printf("Digite o valor do angulo teta em graus em relação à horizontal ");
  scanf("%lf",&teta);
  
  teta = teta*acos(0.0)*2/180;
  
  h = (v*v*sin(teta)*sin(teta))/(2*9.8);
  
  printf("A alura maxima da bola em uma gravidade de 9,8 m/s², velocidade inicial de %f m/s e angulo %lf radianos em relação a horizontal eh: %f\n",v,teta,h);
  
  return 0;
}