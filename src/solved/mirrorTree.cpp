#include<bits/stdc++.h>

using namespace std;

struct node{
	int value;
	struct node *left;
	struct node *right;
};

struct node* createNode(int value){
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->value = value;
	root->right = NULL;
	root->left = NULL;
	return root;
}

struct node* mirror(struct node *root){
	if(!root)
		return NULL;

	struct node * temp = root->right;
	root->right = root->left;
	root->left = temp;

	mirror(root->left);
	mirror(root->right);

	return root;
}


struct node* insert(struct node *root,int value){
	if(!root)
		return createNode(value);
	if(root->value>value){
		root->left = insert(root->left,value);
	}else if(root->value<=value){
		root->right = insert(root->right,value);
	}

	return root;
}
	

void preorder(struct node *root){
	if(!root) return;
	cout<<root->value<<" ";
	preorder(root->left);
	preorder(root->right);
}

int isBalancedUtil(struct node* root){
    
    if(!root) return 0;
        
    int left = isBalancedUtil(root->left);
    
    if(left==-1) return -1;
    
    int right = isBalancedUtil(root->right);
    
    if(right==-1) return -1;
    if(abs(left-right)>1) return -1;
    
    return left>right?left+1:right+1;
} 

int isBalanced(struct node* A) {
    if(isBalancedUtil(A)==-1) return 0;
    return 1;    
}
	
	
	
	
int main(){

	int n,v;
	cin>>n;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	for(int i=0;i<n;i++){
		cin>>v;
		root = insert(root,v);
	}
	preorder(root);
	cout<<"\n";
	root = mirror(root);
	preorder(root);
	return 0;
}	