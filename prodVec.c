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
