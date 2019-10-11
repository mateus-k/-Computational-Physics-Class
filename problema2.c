#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){
  
 int c;
 float Vsub, Vcorpo, dagua, dcorpo, pi, Vext, V;
 
  printf("Este programa calcula a porcentagem do volume de três corpos que fica para fora de um fluido, neste caso a água\n\n");
    
  printf("Digite o valor da densidade do material em g/cm³: ");
  scanf("%f",&dcorpo);
  
  printf("Escolha um dos seguintes numeros que corresponde à forma geométrica do corpo: 1 - Esfera, 2 - Paralelepipedo, 3 - Cone: 3   ");
  scanf("%d",&c);
  
   dagua = 1;
   pi = 2*acos(0.0);
  
  if (c == 1){
    float r;
    
    printf("Você escolheu a esfera\n");
    printf("Digite o valor do raio da esfera em cm: ");
    scanf("%f",&r); 
    
    Vcorpo = (4/3)*pi*r*r*r;
    Vsub = (dcorpo/dagua)*Vcorpo;
    Vext = (Vcorpo - Vsub);
    V = (Vext/Vcorpo)*100;
    
  }
  else if ( c == 2){
    float a, b, c;
    
    printf("Você escolheu o paralelepipedo\n");
    printf("Digite o valor do comprimento em cm: ");
    scanf("%f",&a);
    printf("Digite o valor da largura em cm: ");
    scanf("%f",&b);
    printf("Digite o valor da altura em cm: ");
    scanf("%f",&c);
    
    Vcorpo = a*b*c;
    Vsub = (dcorpo/dagua)*Vcorpo;
    Vext = (Vcorpo - Vsub);
    V = (Vext/Vcorpo)*100;
  }
  else if (c == 3){
     float h, r;
    
    printf("Você escolheu o cone\n");  
    printf("Digite o valor do raio da base em cm: ");
    scanf("%f",&r);
    printf("Digite o valor da altura em cm: ");
    scanf("%f",&h);
    
    Vcorpo = pi*r*r*h/3;
    Vsub = (dcorpo/dagua)*Vcorpo;
    Vext = (Vcorpo - Vsub);
    V = (Vext/Vcorpo)*100;
  }
  else {
    printf("O programa desconhece este numero para a forma geometrica\n");
  }
  
  printf("A porcentagem do volume para fora da água é: %f%\n",V);
  
 return 0;
}