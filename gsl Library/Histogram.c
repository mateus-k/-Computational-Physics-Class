/*para compilar 'gcc -static Histogram.c -lgsl -lgslcblas -lm -o Histogram.out'*/

#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>

int main(void){

	size_t n=100;
	double *range;
	double *bin;

	/*criado um histograma h com tamanho 'n'*/
	gsl_histogram *h = gsl_histogram_alloc(n);
	
	/*definindo o range do histograma*/
	const double xmin=-3;
	const double xmax=3;
	
	/*criad um 'bins' uniformes com o range definido*/
	gsl_histogram_set_ranges_uniform(h,xmin,xmax);


return 0;
}
