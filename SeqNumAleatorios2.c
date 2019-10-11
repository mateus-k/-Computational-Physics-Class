#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

double ran1(long *idum);

int main(void){
  
  long int semente;
  int i, N;
  double aleatorio, x;
  FILE *arq;
  
  
  arq = fopen ("numAleatorios.dat", "w");
  if (arq == NULL){
    printf("Erro de leitura!!");
    exit(1);
  }
 
  printf("Digite a quantidade de números que deseja: ");
  scanf("%d",&N);
  printf("Digite o máximo valor a ser gerado: ");
  scanf("%lf",&x);
  printf("Digite a semente: ");
  scanf("%ld",&semente);
  
  for (i=0; i<N; i++){
    aleatorio = ran1(&semente);
    aleatorio = (aleatorio - 0.5)*2.0*x;  //Ele gera de [-1, 1) e multiplica pelo numero que queres caso x=100 fica [-100, 100)
    //printf("A semente é: %ld\n",semente);
    printf("%lf\n", aleatorio);  
    fprintf(arq, "%lf\n", aleatorio); 
  }  
  
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

double ran1(long *idum) {
  int j;
  long k;
  static long iy=0;
  static long iv[NTAB];
  double temp;
   
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
