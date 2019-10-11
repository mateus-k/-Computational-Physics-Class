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
  
  printf("Este programa calcula o tempo de queda, a altura maxima e a distancia de um projétil em uma gravidade de %.1lfm/s² e imprime um arquivo de dados (x,y)\n\n",g);
  printf("Para isso é necessário digitar o valor da velocidade inicial em m/s: ");
  scanf("%lf",&v0);
  printf("\n");
  printf("O valor em m da altura inicial relativa ao nivel do mar igual a zero e negativo caso abaixo: ");
  scanf("%lf",&y0);
  printf("\n");
  printf("A altura em m do alvo ao nivel do mar igual a zero e negativo caso abaixo: ");
  scanf("%lf",&y);
  printf("\n");
  printf("O menor angulo em graus da velocidade com relação ao solo: ");
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
    
    arq = fopen("trajetoriaBalistica2D.dat", "w");
    if (arq == NULL){
      printf("erro na abertura do arquivo trajetoriaBalistica2D.dat\n");
      exit(EXIT_FAILURE);
    }
    
    printf("Um arquivo .dat foi criado com os pontos (x,y)\n");
    for (i = 0; i<N; i++){
      t = t0 + dt*i;
      
      yp = y0 + vy*t+ g*t*t/2;
      x = vx*t;
      
      fprintf(arq, "%f  %f\n",x,yp);
    }
    
    fclose(arq);
    
    return 0;
  }
  
    
    
