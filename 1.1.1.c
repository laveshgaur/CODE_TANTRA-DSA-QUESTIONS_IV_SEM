#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node *insert(struct node *root){
	int data;
	scanf("%d",&data);
	if(data==-1){
		return NULL;
	}
	root=(struct node *)malloc(sizeof(struct node));
	root->data=data;
	root->left=insert(root->left);
	root->right=insert(root->right);
	return root;
}

void inorder(struct node *root){
	if(root==NULL)return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
int main(){
	struct node *root=NULL;
	root=insert(root);
	inorder(root);
	return 0;
}