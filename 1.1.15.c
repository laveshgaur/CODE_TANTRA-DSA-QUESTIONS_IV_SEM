#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n>=0 && n<=10){
		int matrix[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
			}
		}
		if(n==1){
			printf("0");
		}else{
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d ",matrix[i][j]);
				}
				printf("\n");
			}
		}
	}else{
		printf("-1");
	}
	return 0;
}
