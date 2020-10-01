// https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/remove-friends-5/
#include<bits/stdc++.h>

using namespace std;

struct node{
    
    int val = 0;
    node * left = NULL;
    node * right = NULL;
};

int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        int n,k;
        cin>>n>>k;

        node* head = NULL;
        node* ptr = NULL;
        node* temp = NULL;
        
        for(int i = 0;i<n;i++){
            temp = (node*)malloc(sizeof(node));
            cin>>temp->val;
            
            if(!head){
                head = temp;
                ptr = temp;
            }else{
                ptr->right = temp;
                temp->left = ptr;
                ptr = temp;
            }
            
        }
        // cout<<"start\n";
        // ptr = head;
        // while(ptr){
        //     // cout<<head->val<<"here\n";
        //     cout<<ptr->val<<" ";
        //     ptr = ptr->right;
        // }
        // cout<<"\n";
        // cout<<"end\n";
        
        ptr = head;
        while(k){
            
            if(ptr==head){
                if(ptr->right->val>ptr->val){
                    ptr = ptr->right;
                    ptr->left = NULL;
                    free(head);
                    head = ptr;
                    k--;
                }else{
                    ptr = ptr->right;
                }
            }else{
                if(ptr->right->val>ptr->val){
                    temp = ptr;
                    ptr->left->right = ptr->right;
                    ptr->right->left = ptr->left;
                    ptr = temp->left;
                    free(temp);
                    k--;
                }else{
                    ptr = ptr->right;
                }
            }
        }
        
        ptr = head;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->right;
        }
        cout<<"\n";
    }
    return 0;
}