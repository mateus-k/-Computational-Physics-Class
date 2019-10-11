#include <stdio.h>
#include <math.h>

int main(void){
  
  double a,b,c;
  double discr;
  double x1,x2;
  
  printf("Este programa resolve uma equação de segundo grau:\n");
  printf("  ax*x + bx + c = 0\n\n");
  
  printf("Favor digite o valor de a: ");
  scanf("%lf", &a);
  
  printf("Favor digite o valor de b: ");
  scanf("%lf", &b);
  
  printf("Favor digite o valor de c: ");
  scanf("%lf", &c);
  
  //calculo do discriminante
  
  discr = pow(b,2.0) - 4.0*a*c;
  
  //teste do sinal 
  
  if (discr >= 0.0){
    
    printf("As raizes são reais! \n"); 
    x1 = (-b + sqrt(discr)) / (2.0*a);
    x2 = (-b - sqrt(discr)) / (2.0*a);
    
  printf("As raizes da equação %lf*x*x + %lf*x + %lf são:\n",a,b,c);
  printf("x1 = %lf\n", x1);
  printf("x2 = %lf\n",x2);
    
  }else{
    double Real,Im;
   
    Real = -b / (2.0*a);
    Im = sqrt(-discr)/(2.0*a); 
    
  printf("As raizes da equação %lf*x*x + %lf*x + %lf são complexas:\n",a,b,c);
  printf("x1 = %lf + %lf i\n", Real,Im);
  printf("x2 = %lf - %lf i\n",Real,Im);
 }
 
  return 0;
}
