#include<stdio.h>
int main(){
	int v;
	scanf("%d",&v);
	int limit=v*(v-1)/2;
	if(v<1 || v>10){
		printf("Invalid number");
	}else{
		int e;
		scanf("%d",&e);
		if(e<0 || e>limit){
			printf("Invalid number");
		}
		else{
			int matrix[v][v];
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					matrix[i][j]=0;
				}
			}
			for(int i=0;i<e;i++){
				int src,des;
				scanf("%d",&src);
				scanf("%d",&des);
				matrix[src][des]=1;
				matrix[des][src]=1;
			}
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					printf("%d ",matrix[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}