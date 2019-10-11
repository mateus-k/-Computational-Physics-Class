#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

float *prodVec(float *v1, float *v2){

  int i, j ,k;
  float *resp, Eijk;

  resp = malloc (3 * sizeof(float));
  
  for (i = 0; i<3; i++){
      resp[i]=0.0;
      for (j = 0; j<3; j++){
           for (k = 0; k<3; k++){
             Eijk = (i - j)*(j - k)*(k - i)/2.0;  //retirado do en.wikipedia 
	     resp[i] = resp[i] + Eijk * v1[j] * v2[k];
	   }
       } 
  }
  return resp;
 
}

int main(void){

  int i;
  float *a, *b, *c;
  
  a = malloc (3 * sizeof(float));
  b = malloc (3 * sizeof(float));
  c = malloc (3 * sizeof(float));
  
  printf("Digite as coordenadas do vetor 1 separados por vírgula: ");
  scanf("%f, %f, %f", a, a+1, a+2);
  
  printf("Digite as coordenadas do vetor 2 separados por vírgula: ");
  scanf("%f, %f, %f", b, b+1, b+2);
  
   c = prodVec(a, b);
  
   printf("%fi%+fj%+fk\n", c[0], c[1], c[2]);
  
  return 0;
}

