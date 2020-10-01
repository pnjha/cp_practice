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

	// temp1->next = head->next;
	// cout<<"here\n";
	// counter = 0;
 //    temp1 = head;

 //    while(temp1!=NULL){
 //    	cout<<"fuck\n";
 //        temp1 = temp1->next;
 //        counter++;
 //    }

	bool flag = false;

	if(head->next==NULL||head==NULL)
		cout<<"No loop found\n";
	else{

		temp1 = head;
		temp2 = head;

		while(temp1&&temp2){

			temp1 = temp1->next;
			if(temp2->next==NULL||temp2->next->next==NULL){
				flag = false;
				break;
			}else{
				temp2 = temp2->next->next;	
			}

			if(temp1==temp2){
				flag = true;
				break;
			}
		}

		if(flag) cout<<"Loop detected\n";
		else cout<<"Loop not detected\n";
	} 

	return 0;
}