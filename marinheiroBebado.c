#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

float ran1(long *idum);

int main(void){
  
  long int semente;
  int i, N, x ,y, passos;
  float aleatorio, probabilidade;
  FILE *arq;
  
  semente= -6517547;
  
  x=0; y=0; passos=0;
  
  printf("Este programa faz uma simulação da trajetória de um bêbado.\n");
  
  
  arq = fopen("caminhoDoBebado.dat", "w");
  if (arq == NULL){
    printf("ERRO NA ABERTURA DO ARQUIVO 'caminhoDoBebado.dat' !\n");
    exit(EXIT_FAILURE);
  }
    

  
  printf("(x , y) e quantidade de passos\n");
  while  ((y<50) &&  (x<10) && (x>-10)){
    aleatorio = ran1(&semente);
    if (aleatorio>=0.50){
      y += 1;          //passo para frente
    } else if ((aleatorio>0.25) && (aleatorio<50)){
      x -= 1;            //passo para esquerda
    } else {
      x += 1;          //passo para direita
    }  
    passos += 1;
    printf("(%d , %d) %d passos\n",x ,y,passos);
    fprintf(arq, "%d %d\n",x, y);
  }
 
   probabilidade = (float) y / (float) passos;
   printf("Esta é a probabilidade do marinheiro chegar no barco: %f.\n",probabilidade);
    
  fclose(arq);
  
  return 0;
}


//------------------------------------------------------------------//

//gerador de números aleatórios//

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float ran1(long *idum) {
  int j;
  long k;
  static long iy=0;
  static long iv[NTAB];
  float temp;
   
  if (*idum <= 0 || !iy) {
    if (-(*idum) < 1) *idum=1;
    else *idum = -(*idum);
    for (j=NTAB+7;j>=0;j--) {
      k=(*idum)/IQ;
      *idum=IA*(*idum-k*IQ)-IR*k;
      if (*idum < 0) *idum += IM;
      if (j < NTAB) iv[j] = *idum;
    }
    iy=iv[0];
  }
  k=(*idum)/IQ;
  *idum=IA*(*idum-k*IQ)-IR*k;
  if (*idum < 0) *idum += IM;
  j=iy/NDIV;
  iy=iv[j];
  iv[j] = *idum;
  if ((temp=AM*iy) > RNMX) return RNMX;
  else return temp;
}
#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX