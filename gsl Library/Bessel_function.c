/*baseado no link <https://www.gnu.org/software/gsl/doc/html/usage.html>
Para compilar 'gcc -static Bessel_function.o -lgsl -lgslcblas -lm'*/

#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

int main (void)
{
  double x = 5.0;
  double y = gsl_sf_bessel_J0 (x);
  printf ("J0(%g) = %.18e\n", x, y);
  return 0;
}

/*output 'J0(5) = -1.775967713143382642e-01' */
