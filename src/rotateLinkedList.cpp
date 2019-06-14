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

struct node* rotateRight(struct node* A, int B) {
    
    if(A->next==NULL||A==NULL)
        return A;
    
    struct node *head = A, *tail = A, *pivot = A, *prev = A;
    cout<<"here\n";
    int size =  0;
    while(head!=NULL){
        head = head->next;
        size++;
    }
    
    B = B%size;
    cout<<B<<"\n";
    head = A;
    
    int count = B-1;
    
    if(B==0)
        return A;

    while(count--){
        tail = tail->next;
    }
    
    count = B;

    while(tail->next!=NULL){
        prev = pivot;
        pivot = pivot->next;
        tail = tail->next;
    }
    
    prev->next = NULL;
    tail->next = head;
    
    head = pivot;
    
    return head;
    
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

    head = rotateRight(head,90);

    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }

    cout<<"\n";

    return 0;
}
