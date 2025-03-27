#include<stdio.h>
#include<stdlib.h>

struct node {
	int vertex;
	struct node *next;
};

struct Graph{
	int vertices;
	struct node **adjacency;
};

struct Graph *createGraph(int vertices){
	struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
	graph->adjacency=(struct node **)malloc(vertices*sizeof(struct node));
	graph->vertices=vertices;
	for(int i=0;i<vertices;i++)
		graph->adjacency[i]=NULL;
	return graph;
}

struct node *createNode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->vertex=data;
	newnode->next=NULL;
	return newnode;
}

struct node *insert(struct node *head,struct node *newnode){
	if(head==NULL){
		return newnode;
	}else{
		struct node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		return head;
	}
}

struct Graph *addEdge(struct Graph *graph,int src,int des){
	struct node *newnode=createNode(src);
	graph->adjacency[des]=insert(graph->adjacency[des],newnode);
	
	newnode=createNode(des);
	graph->adjacency[src]=insert(graph->adjacency[src],newnode);

	return graph;
}

void DFS(struct Graph *graph,int start,int *visited){
	printf("%d ",start);
	struct node *temp=graph->adjacency[start];
	visited[start]=1;
	while(temp){
		if(!visited[temp->vertex]){
			DFS(graph,temp->vertex,visited);
		}
		temp=temp->next;
	}
}

int main(){
	int vertices,edges;
	scanf("%d",&vertices);
	scanf("%d",&edges);
	struct Graph *graph=createGraph(vertices);

	for(int i=0;i<edges;i++){
		int src,des;
		scanf("%d %d",&src,&des);
		graph=addEdge(graph,src,des);
	}
	int start;
	scanf("%d",&start);
	int *visited=calloc(vertices,sizeof(int));
	DFS(graph,start,visited);
	return 0;
}