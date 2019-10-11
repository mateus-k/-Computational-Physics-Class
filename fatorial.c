#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//fatorial

int main(void){
  
  int i ,x;
  double fatx;
  
  printf ("Digite o valor do número inteiro para fazer o fatorial deste número: ");
  scanf("%d",&x);
  
  fatx = 1.0;
  if (i == 0) {
     printf("Fat(0) = %.0lf\n",fatx);
   }
   else if (x > 0) {
     for (i = 1; i<=x; i++){
      fatx = fatx * i;
     }
  printf("Fatorial %d!= %.0lf\n",x,fatx);
   }
  
  return 0;
}
