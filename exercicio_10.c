#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
  float alpha,beta,gama,del;
  float a, b, c;
  float delta, q, p;
  double x1,x2,x3;
  
  printf("Este programa calcula as raízes de uma equação cúbica na forma αx³ + βx² + γx + δ = 0\n\n");
  printf("Digite os valores de α, β, γ, δ respectivamente: ");
  scanf("%f %f %f %f",&alpha,&beta,&gama,&del);
  
  a = beta/alpha; b = gama/alpha ; c = del/alpha;

  p = (3*b - a*a)/3;
  
  q = (2*a*a*a - 9*a*b + 27*c)/27;
  
  delta = (q/2)*(q/2) + (p/3)*(p/3)*(p/3);
  
  if (delta == 0){
      
    x1 = 2*cbrt(-q/2) - (a/3);
    
    x2 = cbrt(q/2) - (a/3);
        
    x3 = x2;
    
    printf("As raizes são reais com 2 iguais, x1 = %f ; x2 = %f ; x3 = %lf\n",x1, x2, x3);
   
  } else if (delta > 0){
    
    float u, v, xreal, xIm;
    
     u = cbrt((-q/2) + sqrt(delta));
    
     v = cbrt((q/2) + sqrt(delta));
   
     x1 = u + v  + (a/3);
    
     xreal = (-1/2)*(u - v) - (a/3);
    
     xIm = sqrt((3)*(u + v)/2);

    printf("Há duas raizes complexas e uma real, x1 = %f ;  x2 = (%f + %fi) ; x3 = (%f - %fi)\n",x1,xreal,xIm,xreal,xIm);
  
  } else if (delta < 0){
  
    float r, fi, pi;
    
    pi = 2*acos(0.0);
    
    r = sqrt((-p/3)*(-p/3)*(-p/3));
    
    fi = acos(-q/(2*r));
    
    x1 = 2*cbrt(r)*cos(fi/3) - a/3;
   
    x2 = 2*cbrt(r)*cos((fi + 2*pi)/3) - a/3;
   
    x3 = 2*cbrt(r)*cos((fi + 4*pi)/3) - a/3;
  
    printf("As raizes são reais, x1 = %lf ; x2 = %lf ; x3 = %lf\n",x1,x2,x3);
  }
  return 0;
}