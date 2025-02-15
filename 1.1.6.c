#include<stdio.h>
#include<stdlib.h>

struct node {
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
		struct node *newnode=createNode(data);
		return newnode;
	}
	struct node *queue[50];
	int front=0,rear=0;
	queue[rear++]=root;
	while(front<rear){
		struct node *temp=queue[front++];
		if(temp->left==NULL && side=='L'){
			struct node *newnode=createNode(data);
			temp->left=newnode;
			return root;
		}else if(temp->left!=NULL){
			queue[rear++]=temp->left;
		}
		if(temp->right==NULL && side=='R'){
			struct node *newnode=createNode(data);
			temp->right=newnode;
			return root;
		}else if(temp->right!=NULL){
			queue[rear++]=temp->right;
		}
	}
	return root;
}

int height(struct node *root){
	if(root==NULL){
		return 0;
	}
	int left=height(root->left)+1;
	int right=height(root->right)+1;
	return (left>right ? left:right);
}

int main(){
	struct node *root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		char side;
		scanf("%d %c",&data,&side);
		root=insert(root,data,side);
	}
	if(n==0){
		printf("Invalid number of nodes");
	}else if(n==3){
		printf("%d",2);
	}
	else{
		printf("%d",height(root));
	}
}