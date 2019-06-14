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

int main(){

	int n,val;
	cin>>n;

	struct node* head = NULL, *temp1 = NULL, *temp2 = NULL;

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

	temp1 = head;
	temp2 = head;

	if(head->next==NULL||head->next->next==NULL)
		cout<<"Middle element: "<<head->value<<"\n";
	else{

		while(temp2->next!=NULL&&temp2->next->next!=NULL){

			temp1 = temp1->next;
			temp2 = temp2->next->next;

		}

		cout<<"Middle element: "<<temp1->value<<"\n";

	}


	return 0;
}