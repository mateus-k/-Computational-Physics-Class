#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){
 
  int i;
  i=0;
  
  while (true){
    
    printf("%d\n",i);
    i++;
    if (i>=10){
    break;
    }
  }
  
  return 0;
}
