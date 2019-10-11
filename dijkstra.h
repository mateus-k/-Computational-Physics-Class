#include "edgelength.h" // double edgelength[998][998]
#define INFINITY 9999.999999

void dijkstra(int startnode){
 
   	double distance[n],mindistance;
    int visited[n],count,pred[n],nextnode,i,j;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++){
      distance[i]=edgelength[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1){
        mindistance=INFINITY;
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]< mindistance && !visited[i]){
              mindistance=distance[i];
              nextnode=i;
            }
            
            //check if a better path exists through nextnode       
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+edgelength[nextnode][i]<distance[i]){
                        distance[i]=mindistance+edgelength[nextnode][i];
                        pred[i]=nextnode;
                    }
    	count++;
    }
 
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode){
          printf("\nPeso total do caminho até o nodulo %d: %lf",i,distance[i]);
          printf("\nCaminho: %d",i);
          j=i;
          do{
          	j=pred[j];
            printf("<-%d",j);
          }while(j!=startnode);
    		}
	printf("\n");
}
