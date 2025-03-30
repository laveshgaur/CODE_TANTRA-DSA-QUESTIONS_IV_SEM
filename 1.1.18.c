#include<stdio.h>
#include<stdlib.h>

void BFS(int v,int adjMatrix[][v],int start){
	printf("%d ",start);
	int *visited=calloc(v,sizeof(int));
	visited[start]=1;
	int queue[1000];
	int front=0,rear=0;
	queue[rear++]=start;
	while(front<rear){
		int row=queue[front++];
		for(int j=0;j<v;j++){
			if(adjMatrix[row][j]==1 && !visited[j]){
				printf("%d ",j);
				visited[j]=1;
				queue[rear++]=j;
			}
		}
	}
}

int main(){
	int v;
	scanf("%d",&v);
	int e;
	scanf("%d",&e);
	int adjMatrix[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			adjMatrix[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int src,des;
		scanf("%d %d",&src,&des);
		adjMatrix[src][des]=1;
		adjMatrix[des][src]=1;
	}
	int start;
	scanf("%d",&start);
	BFS(v,adjMatrix,start);
	return 0;
}