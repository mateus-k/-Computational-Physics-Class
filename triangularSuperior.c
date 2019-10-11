#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void triangularSuperior(int n, float **A, float *b){
  
  int i, j, k;
  float lambda;
  
  for (i=0; i<n-1; i++){
    for (j = i+1; j<n; j++){
      lambda = A[j][i] / A[i][i];
      for (k=0; k<n; k++){
	A[j][k]  -= lambda * A[i][k]; 
      }
      b[j] -= lambda * b[i];
    }
  }

}

