#include<bits/stdc++.h>

using namespace std;

struct node{
    
    int val = 0;
    struct node * left = NULL;
    struct node * right = NULL;
};

int main(){
    
 	struct node *a = (struct node*)malloc(sizeof(node)); // both type of declaration works

 	node *ptr = a;

 	a->val = 10;

 	cout<<a->val<<"\n";
	cout<<ptr->val<<"\n";
    
    return 0;
}