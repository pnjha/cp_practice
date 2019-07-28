#include<bits/stdc++.h>

using namespace std;

struct node{

	int value;
	struct node *next;
};

//convert first list to circular ll and then traversing second 
//list ptr steps equal to size of the cycle. Now with this prt along
//with a ptr at begining of second list move them simultaneously
//where ever the are equal thats intersecting point

struct node* intersection(struct node* head1, struct node* head2){

	struct node *firstTail = NULL, *h1 = head1, *h2 = head2;
	struct node *intersetionPoint = NULL, *temp = head2;
	int cycleLen = 0;	

	while(h1->next!=NULL){
		h1 = h1->next;
		cycleLen++;
	}

	firstTail = h1;
	cycleLen++;
	h1->next = head1;

	h1 = head2;

	while(cycleLen--){
		h1 = h1->next;
	}

	while(h1!=h2){
		h1 = h1->next;
		h2 = h2->next;
	}

	firstTail->next = NULL;
	return h1;
}

int main(){

	struct node* newnode; 
	struct node* head1 = (struct node*) malloc(sizeof(struct node)); 
	head1->value  = 10; 

	struct node* head2 = (struct node*) malloc(sizeof(struct node)); 
	head2->value  = 3; 

	newnode = (struct node*) malloc (sizeof(struct node)); 
	newnode->value = 6; 
	head2->next = newnode; 

	newnode = (struct node*) malloc (sizeof(struct node)); 
	newnode->value = 9; 
	head2->next->next = newnode; 

	newnode = (struct node*) malloc (sizeof(struct node)); 
	newnode->value = 15; 
	head1->next = newnode; 
	head2->next->next->next  = newnode; 

	newnode = (struct node*) malloc (sizeof(struct node)); 
	newnode->value = 30; 
	head1->next->next= newnode; 

	head1->next->next->next = NULL; 

	newnode = intersection(head1,head2);

	cout<<"Intersection point at: "<<newnode->value<<"\n";

	return 0;
}