#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node *createNode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

struct node *insert(struct node *root,int data,char side){
	if(root==NULL){
		return createNode(data);
	}
	struct node *queue[100];
	int front=0,rear=0;
	queue[rear++]=root;
	while(front<rear){
		struct node *temp=queue[front++];
		if(side=='L'){
			if(temp->left==NULL){
				temp->left=createNode(data);
				return root;
			}
			else{
			queue[rear++]=temp->left;
			}
		}
		if(side=='R'){
			if(temp->right==NULL){
				temp->right=createNode(data);
				return root;
			}else{
				queue[rear++]=temp->right;
			}
		}
	}
	return root;
}

int checkBalanced(struct node *root,int *height){
	if(root==NULL){
		(*height)=0;
		return 1;
	}
	int left=0,right=0;
	int leftbalance=checkBalanced(root->left,&left);
	if(!leftbalance){
		return 0;
	}
	int rightbalance=checkBalanced(root->right,&right);
	if(!rightbalance){
		return 0;
	}
	(*height)=(left>right ? left:right)+1;
	if(abs(left-right)>1){
		return 0;
	}
	return 1;
}

int main(){
	int n, rootValue;
	scanf("%d",&n);
	scanf("%d",&rootValue);
	struct node *root=createNode(rootValue);
	for(int i=0;i<n-1;i++){
		int data;
		char side;
		scanf("%d %c",&data,&side);
		root=insert(root,data,side);
	}
	int height=0;
	if(checkBalanced(root,&height)){
		printf("Balanced");
	}else{
		printf("Not balanced");
	}
	return 0;
}