#include <stdio.h> //FILE
#include <stdlib.h> //malloc

double **Scanfadj(const int n, double **adj){

	int i,j;
	FILE *fadjA;
	
	//==Caminho de onde está armazenado o connectoma
	//fadjA = fopen("/home/mateusk/Documents/Mestrado/Connectomes/CIJ_fbden_average.txt","r");
	fadjA = fopen("CIJ_edgelength_average.txt","r");
	
	//==Lê a matriz de adjacência e aloca no array adjA[i][j]
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			fscanf(fadjA,"%lf,",&adj[i][j]);
		}
	}
	fclose(fadjA);
	
return adj;

}
