#include<bits/stdc++.h>

using namespace std;

struct node{

	int value;
	struct node *left;
	struct node *right;
};

struct listNode{

	int value;
	struct listNode *left;
	struct listNode *right;
	struct listNode *down;
};

struct node* createNode(int value){

	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->value = value;
	root->left = NULL;
	root->right = NULL;

	return root;
}

struct node* insert(struct node* root,int value){

	if(root==NULL){

		return createNode(value);

	}else if(root->value > value){

		root->left = insert(root->left,value);

	}else if(root->value < value){

		root->right = insert(root->right,value);
	}
	return root;
}

void tVUtil(struct node* root,int distance,struct listNode* ll){

	if(root==NULL)
		return;
	
	ll->value = distance;
	
	struct listNode *temp1 = (struct listNode *)malloc(sizeof(struct listNode));
	temp1->value = root->value;
	temp1->left = NULL;
	temp1->right = NULL;
	temp1->down = NULL;

	struct listNode *temp2 = ll;
	
	while(temp2->down!=NULL)
		temp2 = temp2->down;

	temp2->down = temp1;
	
	struct listNode *temp = NULL;

	if(root->left){
		if(!ll->left){
			temp = (struct listNode *)malloc(sizeof(struct listNode));
			temp->right = ll;
			ll->left = temp;	
			tVUtil(root->left,distance-1,temp);
		}else{
			tVUtil(root->left,distance-1,ll->left);
		}
	}
	if(root->right){
		if(!ll->right){
			temp = (struct listNode *)malloc(sizeof(struct listNode));
			temp->left = ll;
			ll->right = temp;
			tVUtil(root->right,distance+1,temp);
		}else{
			tVUtil(root->right,distance+1,ll->right);
		}
	}

}

void topview(struct node* root){

	struct listNode* ll = (struct listNode *)malloc(sizeof(struct listNode));
	struct listNode* temp = NULL;	
	tVUtil(root,0,ll);

	while(ll->left)
		ll = ll->left;

	while(ll){
		temp = ll->down;
		while(temp){						//modify this logic to print top view/ bottom view/ left view / right view
			cout<<temp->value<<" ";
			temp = temp->down;
		}
		cout<<"\n";
		ll = ll->right;
	}
}

void inorder(struct node *root){
	
	if(!root)
		return;
	
	inorder(root->left);
	cout<<root->value<<" ";
	inorder(root->right);
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
	struct node *root = NULL;
	for(int i=0;i<n;i++){
		cin>>v;
		root = insert(root,v);
	}
	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	topview(root);
	
	return 0;
}