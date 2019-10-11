#include <stdlib.h>
#include <stdio.h>
//#include "connectome.h" // double adj[998][998]
//#include "connectomeBin.h" //double adjBin[998][998]
#define n 998

#include "dijkstra.h"

struct Graph{

	int degree;
	int edge[100];
	double weight[100];
};

int main(void){
	
	int i,j,k,u;
	struct Graph node[n];
	

	
	/*
	//Zerando grau dos nodulos
	for (k=0; k<n; k++){
		node[k].degree = 0;
	}
	
	//Calculando grau de nodulos
	for (i=0; i<n; i++){
		for (k=0; k<n; k++){
			if (adj[i][k]>0){
				node[i].degree++;
			}
		}
	}

	//Montando lista de adjacencia
	for (i=0; i<n; i++){
		j=0;
		for (k=0; k<n; k++){
			if (adj[i][k]>0){
				node[i].edge[j]=k;
				node[i].weight[j]=adj[i][k];
				j++;
			}
		}
	}
	*/
	printf("Digite o nódulo inicial: "); 
	scanf("%d",&u);
	dijkstra(u);
		
	/*for (k=0; k<n; k++)
		printf("grau do nódulo %d %d\n",k,node[k].degree);
	}
	for (k=0; k<n; k++){
		printf("node[%d]:  ",k);
		for (i=0; i<node[k].degree; i++){
			 printf("%d (%lf), ",node[k].edge[i],node[k].weight[i]);
		}
		printf("\n");
	}*/

return 0;
}
 

