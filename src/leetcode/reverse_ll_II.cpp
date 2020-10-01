#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};
 
struct ListNode* createNode(int val){

    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    root->val = val;
    root->next = NULL; 
    return root;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    ListNode *prev = NULL, *present = head, *next = head, *p = NULL; 

    if(!head||!head->next)
        return head;
    
    if(n == m)
        return head;
    
    while(m>1){
        p = prev; 
        prev = present;
        present = present->next;
        cout<<(p?p->val:-1)<<" "<<present->val<<" \n";
        m--;
    }
    
    next = present->next;

    while(n--){

        present->next = prev;
        prev->next = NULL;
        prev = present;

        if(p)
            p->next = present;

        present = next;
        if(next!=NULL)
            next = next->next;
        else
            break;
    }

    return head;
}

int main(){

    int n,x,y,val,counter=0;
    
    n = 5;
    x = 2;
    y = 4;

    struct ListNode* head = NULL, *temp1 = NULL, *temp2 = NULL;
    struct ListNode* tail = NULL;

    vector<int> arr = {1,2,3,4,5};

    for(int i = 0;i<arr.size();i++){
        if(head==NULL){
            head = createNode(arr[i]);
            temp1 = head;
        }else{
            temp2 = createNode(arr[i]);
            temp1->next = temp2;
            temp1 = temp2;
            temp2 = NULL;
        }
    }

    head = reverseBetween(head,x,y);

    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }

    cout<<"\n";

    return 0;
}