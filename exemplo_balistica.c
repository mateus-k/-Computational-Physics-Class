#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void){
  
  double v0,theta,y0,y;
  double T,X,Y;
  double vx,vy,t1,t2,tv;
  float g = -9.8;
  float pi;
  float t0, tf, t, yp, x, dt;
  int i, N;
  FILE *arq;
  
  printf("Este programa calcula o tempo de queda, a altura maxima e a distancia de um projétil em uma gravidade de 9,8m/s²\n\n");
  printf("Digite o valor da velocidade inicial em metros por segundo: ");
  scanf("%lf",&v0);
  printf("\n");
  printf("Digite o valor da altura inicial em metros relativo ao nivel do mar igual a zero e negativo caso esteja abaixo )): ");
  scanf("%lf",&y0);
  printf("\n");
  printf("Digite a altura do alvo em metros relativo ao nivel do mar igual a zero e negativo caso esteja abaixo: ");
  scanf("%lf",&y);
  printf("\n");
  printf("Digite o menor angulo em graus da velocidade em relação ao solo: ");
  scanf("%lf",&theta);
  printf("\n\n");
  
  //achando pi
  pi = 2*acos(0.0);
  
  //Transformando o theta em radianos
  theta = theta*(pi/180.0);
  
  //Decompondo a velocidade
  vx = v0*cos(theta);
  
  vy = v0*sin(theta);
  
  // A equacao quando o projetil atinge o solo é y = y0 + vyt + 1/2gt²
  // isolando t para saber o tempo de queda temos uma equação de segundo grau 1/2gt² + vyt + (y0 - y) = 0  
  
  t1 = (-vy + sqrt(vy*vy - 2*g*(y0-y)))/g;
  
  t2 = (-vy - sqrt(vy*vy - 2*g*(y0-y)))/g;
  
  if (t2>=t1){
    tv = t2;
  }else{
    tv = t1;
  }
   printf("O tempo o qual o projetil fica no ar é: %lf segundos\n\n",tv);
    
    //Com o tempo de queda usando X = x0 + vxt com x0 = 0 temos a distancia maxima
    X = vx*tv;
    
    printf("A distancia do ponto incial até o alvo é: %lf metros\n\n",X);
    
    //utilizando a equação vy = voy + gt com vy = 0 podemos achar o tempo T onde ocorre a altura maxima 
    T = -vy/g;
    
    //agora com o tempo T é possivel achar a altura maxima com a equaçao Y = y0 + vyt + 1/2gt² 
    Y = y0 + vy*T + g*T*T/2;
    
    printf("A altura maxima que o projetil atinge é: %lf metros\n\n",Y);
    
    t0 = 0;
    tf = tv;
    
    printf("Digite o numero de pontos N: ");
    scanf("%d",&N);
  
    dt = (tf - t0)/(N - 0);
    
    arq = fopen("trajetoria.dat", "w");
    if (arq == NULL){
      printf("erro na apertura do arquivo trajetoria.dat\n");
      exit(EXIT_FAILURE);
    }
    
    printf("Os pontos são (x ; y)\n");
    for (i = 0; i<N; i++){
      t = t0 + dt*i;
      
      yp = y0 + vy*t+ g*t*t/2;
      x = vx*t;
      
      fprintf(arq, "%f  %f\n",x,yp);
    }
    
    fclose(arq);
    
    return 0;
  }
  
    
    