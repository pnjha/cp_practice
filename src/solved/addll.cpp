#include<bits/stdc++.h>

using namespace std;

struct node {

    int val;
    struct node* next;    
};

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
        
    struct node* head = NULL,*temp = NULL,*ptr = NULL;
    int carry = 0;
    
    while(l1!=NULL&&l2!=NULL){
        
        if(head==NULL){
            head = (struct node*)malloc(sizeof(struct node));
            head->val = l1->val + l2->val;
            if(head->val>9){
                carry = 1;
                head->val %= 10;
            }
            temp = head;
            temp->next = NULL;
        }else{
            
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->val = l1->val + l2->val + carry;
            if(ptr->val>9){
                carry = 1;
                ptr->val %= 10;
            }else{
                carry = 0;
            }
            temp->next = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1!=NULL){
        
        if(head==NULL){
            head = (struct node*)malloc(sizeof(struct node));
            head->val = l1->val;
            
            temp = head;
            temp->next = NULL;
        }else{
            
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->val = l1->val;
            temp->next = ptr;
            temp = ptr;
        
        }
        l1 = l1->next;
          
    }
    
    while(l2!=NULL){
        
        if(head==NULL){
            head = (struct node*)malloc(sizeof(struct node));
            head->val = l2->val;
            
            temp = head;
            temp->next = NULL;
        }else{
        
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->val = l2->val;
            temp->next = ptr;
            temp = ptr;
        }
        
        l2 = l2->next;
    }
    
    return head;
}

int main(){

    struct node* newnode; 
    // struct node* head1 = (struct node*) malloc(sizeof(struct node)); 
    // head1->val  = 5; 

    struct node* head1 = NULL;

    struct node* head2 = (struct node*) malloc(sizeof(struct node)); 
    head2->val  = 3; 

    newnode = (struct node*) malloc (sizeof(struct node)); 
    newnode->val = 6; 
    head2->next = newnode; 

    newnode = (struct node*) malloc (sizeof(struct node)); 
    newnode->val = 9; 
    head2->next->next = newnode; 

    newnode = addTwoNumbers(head1,head2);

    while(newnode!=NULL){
        cout<<newnode->val<<" ";
        newnode = newnode->next;
    }
    cout<<"\n";
    return 0;
}