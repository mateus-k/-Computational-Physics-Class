#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "ran1.h"
#include "histogram.h"

	/*A Lei dos Grandes Números diz que 
	a soma N variáveis aletórias independentes e identicamente distribuidas (iid) (variável sum...)
	dividida por N tende a média da distribuição (variável a)*/

main(void){
	
	int *eta, *zeta, sumZeta, sumEta, i, n;
	double *x, *y, sumX, sumY, aux, a;
	long int N, seed;	

	N=10000;
	seed = -time(NULL);
	
	zeta=malloc(N*sizeof(int));
	eta=malloc(N*sizeof(int));
	x=malloc(N*sizeof(double));
	y=malloc(N*sizeof(double));
	if (zeta||eta==NULL||x==NULL||y==NULL){
		printf("erro na alocação de variaveis aleatórias\n");
	}
	
	sumEta=0; sumZeta=0; sumX=0; sumY=0;
	
	
	/*GERADOR DE NÚMEROS ALEATÓRIOS DISCRETOS entre [0,n]*/
	n=1;
	for (i=0; i<N; i++){
		aux=ran1(&seed)*(n+1);
		zeta[i]=(int)aux%(n+1);
		sumZeta += zeta[i];
		//printf("zeta[%d]=%d\n",i,zeta[i]);
	}
	a=(double)sumZeta/N;
	printf("Variável discreta ζ no itervalo [0,%d] Σζ/N --> %lf\n",n,a);
	
	/*GERADOR DE NÚMEROS ALEATÓRIOS DISCRETOS entre [-n,n]*/
	n=1;
	for (i=0; i<N; i++){
		aux=ran1(&seed)*2*(n+1);
		eta[i]=(int)aux%(2*(n+1));
		if (eta[i]>n){
			eta[i] = -eta[i];
			eta[i] += (n+1);
		}
		sumEta += eta[i];
		//printf("eta[%d]=%d\n",i,eta[i]);
	}
	a=(double)sumEta/N;
	printf("Variável discreta η no itervalo [-%d,%d] Ση/N --> %lf\n",n,n,a);
	
	/*GERADOR DE NÚMEROS ALEATÓRIOS CONTÍNUOS no intervalo [0,n]*/
	n=1;
	for (i=0; i<N; i++){
		x[i]=ran1(&seed)*n;
		sumX += x[i];
		//printf("x[%d]=%lf\n",i,x[i]);
	}
	a=sumX/N;
	printf("Variável contínua x no intervalo [0,%d] Σx/N --> %lf\n",n,a);
	
	/*GERADOR DE NÚMEROS CONTÍNUOS no intervalo [-n,n]*/
	n=1;
	for (i=0; i<N; i++){
		y[i]=ran1(&seed)*2*n;
		if (y[i]>n) {
			y[i] = -y[i];
			y[i] += 1;
		}
		sumY += y[i];
		//printf("y[%d]=%lf\n",i,y[i]);
	}
	a=sumY/N;
	printf("Variável contínua y no intervalo [-%d,%d] Σy/N --> %lf\n",n,n,a);	
	
	return 0;
}
