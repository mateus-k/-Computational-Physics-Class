#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void gauss(int n, float **a, float *b){

  int i, j, k;
  float lambda;
  
  for (k=0; k<n-1; k++){
     for (i = k+1; i<n; i++){
        lambda = a[i][k]/a[k][k];
          for (j=k; j<n; j++){
          a[i][j] = a[i][j] - lambda* a[k][j]; 
     }
     b[i]= b[i] -lambda * b[k];
  }
}
}