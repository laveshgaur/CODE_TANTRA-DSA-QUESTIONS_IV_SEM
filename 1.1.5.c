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

int countNodes(struct node *root){
	if(root==NULL)return 0;
	return countNodes(root->left)+countNodes(root->right)+1;
}

int main(){
	struct node *root=NULL;
	root=insert(root);
	printf("%d\n",countNodes(root));
	return 0;
}