//#include<stdio.h>
//#include<conio.h>
#define INFINITE 9999
#define MAX 6
 
void dijkstra(int G[MAX][MAX],int startnode,int *pred, int *distance);
 
int main()
{
	int G[MAX][MAX]=
     {{INFINITE,1,INFINITE,1,INFINITE,INFINITE},
      {1,INFINITE,1,1,INFINITE,INFINITE},
      {INFINITE,1,INFINITE,INFINITE,1,1},
      {1,1,INFINITE,INFINITE,1,INFINITE},
      {INFINITE,INFINITE,1,1,INFINITE,1},
      {INFINITE,INFINITE,1,INFINITE,1,INFINITE}};

	int n=6,u;
	int i,j, pred[MAX]={0}, distance[MAX];
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,u,pred,distance);
	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=u)
		{
			printf("\nDistance of node%d=%d,  ",i,distance[i]);
			printf("Path=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<%d",j);
			}while(j!=u);
	}

}
 
void dijkstra(int G[MAX][MAX],int startnode,int *pred, int *distance)
{
 
	int cost[MAX][MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	int n=MAX;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITE;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITE;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
}
