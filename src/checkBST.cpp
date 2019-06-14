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

//wrong approach
int checkBST(struct node *root){
	if(!root)
		return 1;

	
	int left = checkBST(root->left);
	int right = checkBST(root->right);

	if(left&&right){
		if(root->right==NULL&&root->left==NULL){
			return 1;
		}else if(root->right!=NULL&&root->left==NULL){
			if(root->right->value>=root->value){
				return 1;
			}
		}else if(root->right==NULL&&root->left!=NULL){
			if(root->left->value<root->value){
				return 1;
			}
		}else if(root->right!=NULL&&root->left!=NULL){
			if(root->right->value>=root->value&&root->left->value<root->value){
				return 1;
			}
		}
	}
	return 0;
}


struct node *insert(struct node *root,int value){
	if(!root)
		return createNode(value);
	if(root->value<=value){
		root->left = insert(root->left,value);
	}else if(root->value>value){
		root->right = insert(root->right,value);
	}

	return root;
}
	

void preorder(struct node *root){
	if(!root)
		return;
	cout<<root->value<<" ";
	preorder(root->left);
	preorder(root->right);
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
	if(checkBST(root)==1)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	
	return 0;
}