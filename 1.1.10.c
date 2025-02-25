#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left,*right;
};

int min(struct node *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}

struct node *createNode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

struct node *insert(struct node *root,int data){
	if(root==NULL){
		return createNode(data);
	}
	if(data<root->data){
		root->left=insert(root->left,data);
	}else if(data>root->data){
		root->right=insert(root->right,data);
	}
	return root;
}

struct node *deleteNode(struct node *root,int target){
	if(root==NULL){
		return root;
	}
	if(target<root->data){
		root->left=deleteNode(root->left,target);
	}
	else if(target>root->data){
		root->right=deleteNode(root->right,target);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->left!=NULL && root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else{
			int minValue=min(root->right);
			root->data=minValue;
			root->right=deleteNode(root->right,minValue);
		}
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
	int target;
	scanf("%d",&target);
	root=deleteNode(root,target);
	inorder(root);
	return 0;
}