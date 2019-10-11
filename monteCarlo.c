#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

float ran1(long *idum);
float monteCarlo(long long int n, float r);

int main(void){

   long long int n;
   float r, pi;
   
   r = 1.0;
   n = 1000000000;
  
   pi = 4.0 * r * monteCarlo(n, r);
   
   printf("O valor de pi é %.14f\n", pi);
   
  return 0;

}

float monteCarlo(long long int n, float r){
  
  int i;
  long int semente;
  double ok;
  float media, x, y, fx;
  
  semente = -38292; ok=0;
  
  for (i=0; i<n; i++){
    x = ran1(&semente) * r;
    y = ran1(&semente) * r;
    fx =sqrt(r*r - x*x);
    if (y<= fx){
      ok += 1.0;
    }
  }
  
  media = ok / n;
  
  return media;
}

//=========================================
//gerador de números aleatórios.

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