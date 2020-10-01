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

	int n,val,counter=0;
	cin>>n;
	counter = n;
	struct node* head = NULL, *odd = NULL, *even = NULL, *temp = NULL, *ohead = NULL, *ehead = NULL;

	while(n--){

		cin>>val;
		if(head==NULL){
			head = createNode(val);
			odd = head;
		}else{
			even = createNode(val);
			odd->next = even;
			odd = even;
			even = NULL;
		}
	}

	if(head->next==NULL){
		cout<<"Odd nodes: "<<head->value<<"\n";
		cout<<"Even nodes: \n";
	}else{

		temp = head;
		ohead = temp;
		ehead = temp->next;

		temp = ehead->next;

		ohead->next = NULL;
		ehead->next = NULL;

		odd = ohead;
		even = ehead;

		while(temp!=NULL){

			cout<<"Odd->value: "<<odd->value<<"\n";
			cout<<"Even->value: "<<even->value<<"\n";

			odd->next = temp;
			even->next = temp->next;

			odd = odd->next;
			even = even->next;

			if(even!=NULL)
				temp = even->next;
			else
				temp = NULL;

			if(odd!=NULL)
				odd->next = NULL;
			if(even!=NULL)
				even->next = NULL;
		}

		odd = ohead;
		even = ehead;

		cout<<"Odd nodes: ";

		while(odd!=NULL){
			cout<<odd->value<<" ";
			odd = odd->next;
		}

		cout<<"\nEven nodes: ";

		while(even!=NULL){
			cout<<even->value<<" ";
			even = even->next;
		}

		cout<<"\n";
	}

	return 0;
}