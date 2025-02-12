#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left ,*right;
};

struct node *insert(struct node *root){
	int data;
	scanf("%d",&data);
	if(data==-1)return NULL;
	root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=insert(root->left);
	root->right=insert(root->right);
	return root;
}

void postorder(struct node *root){
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

int main(){
	struct node *root=NULL;
	root=insert(root);
	postorder(root);
	return 0;
}