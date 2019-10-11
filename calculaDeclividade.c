#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

float incliReta(float x1, float y1, float x2, float y2){
  
  float m;

  m = (y2 - y1) / (x2 - x1);

  return m;
}
