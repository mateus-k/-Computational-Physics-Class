#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){

  int i;
  double fi, fim1, fim2;
  
  fi = 0;
  fim1 =0;
  fim2 = 0;
  
  for (i = 0; i <101; i++){;
    
    if (i == 0) {
      fi = 0;
    }
    else if (i == 1){
      fi = 1;
   }
   else if(i > 1){
      fi = fim1 + fim2;
   }
    
    fim2 = fim1;
    fim1 = fi;
    
    printf("%6.0lf ",fi);
 } 
 
   printf("\n");
  return 0;
}