#include<bits/stdc++.h>

using namespace std;

int n=0;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->value = value;
    root->right = NULL;
    root->left = NULL;
    return root;
}

void preorder(struct node *root){
    if(!root)
        return;
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}


struct node* levelOrderInsert(struct node* root){
    int value;
    cin>>value;
    if(!root)
        root = createNode(value);
    n--;
    queue<struct node*> nodes;
    nodes.push(root);
    
    while(!nodes.empty()&&n){
        
        struct node* temp = nodes.front();
        if(temp->left==NULL){
            cin>>value;
            temp->left = createNode(value);
            nodes.push(temp->left);
        }else if(temp->right==NULL){
            cin>>value;
            temp->right = createNode(value);
            nodes.push(temp->right);
        }
        n--;
        nodes.pop();
    }

    return root;
}


int main(){
    int v;
    cin>>n;
    struct node *root = NULL ;
    root = levelOrderInsert(root);
    preorder(root);
    
    return 0;
}