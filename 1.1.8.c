#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node *insert(struct node *root,int data){
	if(root==NULL){
		root=create(data);
	}else{
		if(data<root->data){
			root->left=insert(root->left,data);
		}else{
			root->right=insert(root->right,data);
		}
	}
	return root;
}
int search(struct node *root,int data){
	if(root==NULL){
		return 0;
	}
	if(data<root->data){
		return search(root->left,data);
	}else if(data>root->data){
		return search(root->right,data);
	}
	else{
		return 1;
	}
}
int main(){
	struct node *root=NULL;
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		root=insert(root,data);
	}
	int value;
	scanf("%d",&value);
	if(search(root,value)){
		printf("Found");
	}else{
		printf("Not found");
	}
	return 0;
}