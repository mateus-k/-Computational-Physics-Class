#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void substituicaoRetroativa(int n, float **a, float *b, float *x){
  
  int i, j; 
  
   x[n-1] = b[n-1] / a[n-1][n-1];
   for (i= n-2; i>=0; i--){
     x[i] = b[i];
     for (j=i+1; j<n; j++){
       x[i] -= a[i][j] * x[j];
      }
     x[i] /= a[i][i];
   }
   
}

