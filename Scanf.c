#include <stdio.h>
#include <math.h>

int main(void){
  
  float x1, y1, x2, y2, r;
   
 printf("Este programa calcula a distancia de dois ponto com coordenada (X,Y). Digite a coordenada (X,Y) do primeiro ponto separado por virgula: ");
 scanf("%f, %f",&x1,&y1);
 printf("Digite a coordenada (X,Y) do segundo ponto separado por virgula: ");
 scanf("%f, %f",&x2,&y2);
 
 r = sqrt(pow(x1-x2,2) + pow(y1 - y2,2));
 
 printf("A distancia entre (%f,%f) e (%f,%f) eh: %f\n",x1,y1,x2,y2,r);
 
 return 0;
}
 
  