#include<bits/stdc++.h>

using namespace std;

struct node{

	int val = 0;
	node *left = NULL;
	node *right = NULL;
};

int max(int a, int b){
	return a>b?a:b;
}

node* bst_insert(node* root,int val){
	if(!root){
		root = (node*)malloc(sizeof(node*));
		root->val = val;
		return root;
	}

	if(root->val<val){
		root->right = bst_insert(root->right,val);
	}else{
		root->left = bst_insert(root->left,val);
	}

	return root;
}

int bst_search(node* root,int key, int max_sofar){
	if(!root){
		return INT_MIN;
	}

	max_sofar = max(max_sofar,root->val);

	if(root->val==key){
		return max(max_sofar,root->val);
	}else if(root->val<key){
		return max(max_sofar,bst_search(root->right,key,max_sofar));
	}else{
		return max(max_sofar,bst_search(root->left,key,max_sofar));
	}
}

node* branch_root(node* root,int a,int b){
	if(!root)
		return NULL;
	if(root->val>a&&root->val>b)
		return branch_root(root->left,a,b);
	else if(root->val<a&&root->val<b)
		return branch_root(root->right,a,b);
	else
		return root; 
}

int bst_height(node* root){
	if(!root)
		return 0;
	else
		return max(bst_height(root->left),bst_height(root->right))+1;
}

int main(){

	node* root = NULL;
	int n,a;
	cin>>n;

	for(int i = 0;i<n;i++){
		cin>>a;
		root = bst_insert(root,a);
	}

	cout<<bst_height(root)<<"\n";

	return 0;
}

