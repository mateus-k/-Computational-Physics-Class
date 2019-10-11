#include <stdio.h>
#include <math.h>

int main(void){
  
  int i1, i2;
  float f1, f2;
  double d1, d2;
  
  int *pi;
  float *pf;
  double *pd;
  
 i1 = 100;
 
 printf ("i1 = %d\n", i1);
 
 pi = &i1;
 printf("*pi = %d\n", *pi);
 
 i1 = 200;
 printf("*pi = %d\n", *pi);
 
 i2 = 10;
 pi = i2;
 printf("*pi = %d\n", *pi);
 printf("pi = %p\n", pi);
 printf("&i2 = %p\n", &i2);
 printf("&i1 = %p\n", &i1);
 
 i2 = i1;
 printf("*pi = %d\n",*pi);
 printf("pi = %p\n", pi);
 printf("&i2 = %p\n", &i2);
 printf("&i1 = %p\n", &i1);
 
 
 return 0;
}