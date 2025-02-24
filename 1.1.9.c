#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left,*right;
};

struct node *createNode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

struct node * insert(struct node *root,int data){
	if(root==NULL){
		return createNode(data);
	}
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data){
		root->right=insert(root->right,data);
	}else{
		struct node *newnode=createNode(data);
		return newnode;
	}
	return root;
}

void inorder(struct node *root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main(){
	struct node *root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		root=insert(root,data);
	}
	inorder(root);
	return 0;
}