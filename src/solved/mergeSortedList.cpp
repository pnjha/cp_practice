#include<bits/stdc++.h>
#define size 3
using namespace std;

struct node{

	int value;
	struct node *next;
};

struct node* createNode(int value){

	struct node *root = (struct node*)malloc(sizeof(struct node));	
	root->value = value;
	root->next = NULL;
	return root;
}

struct node* insert(struct node *root, int value){

	if(root==NULL){
		root = createNode(value);
	}else{
		struct node* temp = createNode(value),*t = root;
		while(t->next!=NULL)
			t = t->next;
		t->next = temp;		
	}
	return root;
}

struct node* h = NULL;

void mergeListReverse(struct node* root1, struct node* root2){

	if(root1==NULL)
		return;
	if(root2==NULL)
		return;

	if(root1->value <= root2->value){
		struct node* temp = root1->next;
		root1->next = h;
		h = root1;
		mergeListReverse(temp,root2);
	}else{
		struct node* temp = root2->next;
		root2->next = h;
		h = root2;
		mergeListReverse(root1,temp);
	}
}

struct node* mergeList(struct node* root1, struct node* root2){

	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;


	if(root1->value <= root2->value){
		root1->next = mergeList(root1->next,root2);
		return root1;
	}else{
		root2->next = mergeList(root1,root2->next);
		return root2;
	}
}

int main(){

	cout<<"Enter first list elements(size = 5): ";

	struct node *root1 = NULL;
	int value;

	for(int i=0;i<size;i++){
		cin>>value;
		root1 = insert(root1,value);
	}

	cout<<"Enter second list elements(size = 5): ";

	struct node *root2 = NULL;

	for(int i=0;i<size;i++){
		cin>>value;
		root2 = insert(root2,value);
	}

	// struct node *root = mergeListReverse(root1,root2);
	mergeListReverse(root1,root2);
	struct node *temp = h;	

	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->next;
	}

	cout<<"\n";

	cout<<"First list: ";

	while(root1!=NULL){
		cout<<root1->value<<" ";
		root1 = root1->next;
	}

	cout<<"\n";

	cout<<"Second list: ";

	while(root2!=NULL){
		cout<<root2->value<<" ";
		root2 = root2->next;
	}

	cout<<"\n";


	return 0;
}