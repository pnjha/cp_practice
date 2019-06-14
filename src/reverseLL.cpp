#include<bits/stdc++.h>

using namespace std;

struct node{

	int value;
	struct node *next;
};

struct node* createNode(int value){

	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->value = value;
	root->next = NULL; 
	return root;
}

//recursive solution
struct node* rhead = NULL;

void reverseLLR(struct node* cur,struct node* prev){

	if(cur!=NULL){
		reverseLLR(cur->next,cur);
		cur->next = prev;
	}else{
		rhead = prev; 
	}

}

//Iterative solution

struct node* reverseLLI(struct node* head){

	if(!head)
		return NULL;

	struct node *cur = head,*next = NULL,*prev = NULL;

	while(cur){

		next = cur->next;
		cur->next = prev;
		prev = cur; 
		cur = next;
	}
	return prev;
}

int main(){

	int n,val,counter=0;
	cin>>n;
	counter = n;
	struct node* head = NULL, *temp1 = NULL, *temp2 = NULL;
	struct node* tail = NULL;

	while(n--){

		cin>>val;
		if(head==NULL){
			head = createNode(val);
			temp1 = head;
		}else{
			temp2 = createNode(val);
			temp1->next = temp2;
			temp1 = temp2;
			temp2 = NULL;
		}
	}

	// reverseLLR(head,NULL);	

	rhead = reverseLLI(head);

	while(rhead!=NULL){
		cout<<rhead->value<<" ";
		rhead = rhead->next;
	}

	cout<<"\n";

	return 0;
}