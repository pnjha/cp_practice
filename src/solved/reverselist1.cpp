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


struct node* reverse(struct node* head,int counter){

    if(!head)
        return NULL;

    struct node *cur = head,*next = NULL,*prev = NULL;

    while(counter--){
        // cout<<"inside reverse: "<<cur->value<<"\n";
        next = cur->next;
        cur->next = prev;
        prev = cur; 
        cur = next;
    }
    
    // next = prev;
    // while(next!=NULL){
    //     cout<<"next->value: "<<next->value<<"\n";
    //     next = next->next;
    // }


    return prev;
    

} 
 
 
struct node* reverseBetween(struct node* A, int B, int C) {
    
    if(B==C)
        return A;
        
    struct node *head = A, *tail = A, *temp = NULL,*temp2 = NULL;
    int b = B-1,c = C-1;
    
    while(b--){
        temp = head;
        head = head->next;
    }
    
    // cout<<"head: "<<head->value<<"\n";

    while(c--){
        // cout<<"here\n";
        tail = tail->next;
    }
    
    // cout<<"tail: "<<tail->value<<"\n";

    temp2 = tail->next;
    // if(!temp2)
    //     cout<<"temp2 is null\n";
    
    
    // cout<<"dust\n";

    head = reverse(head,C-B+1);
    

    // cout<<"head: "<<head->value<<"\n";

    
    
    if(B==1)
        A = head;
    else
        temp->next = head;    
        
    head = A;
    
    while(head->next!=NULL)
        head = head->next;
        
    // cout<<head->value<<"\n";    
    head->next = temp2;
    
    // head = A;

    // while(head->next!=NULL){
    //     cout<<"head->next: "<<head->value<<" \n";
    //     head = head->next;
    // }

    return A;
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
    

    head = reverseBetween(head,1,4);

    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }

    cout<<"\n";

    return 0;
}
