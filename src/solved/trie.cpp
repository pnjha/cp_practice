#include<bits/stdc++.h>
using namespace std;

struct node {
    struct node * children[26];
    int countchildren = 0;
    bool isWord = false;
};

struct node *createNode(){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->countchildren = 0;
    root->isWord = false;
    
    for(int i=0;i<26;i++) root->children[i] = NULL;
    return root;
}

void insert(struct node* parent,string inputString){
   int index=0;
   struct node* newNode = NULL;
   for(int i=0;i<inputString.length();i++){
      index = inputString[i]-'a';
      if(parent->children[index]==NULL){
         newNode = createNode();
         parent->children[index] = newNode;
      }
      parent = parent->children[index];
      parent->countchildren++;
   }   
}

int search(struct node* parent,string searchString){
    int index=0;
    for(int i=0;i<searchString.length();i++){
        index = searchString[i]-'a';
        if(parent->children[index]==NULL) 
          return 0;
        parent = parent->children[index];
    }
    return parent->countchildren;
}

int main() {
       
    string str;
    int n,m;
    cin>>n>>m;
    struct node *root = createNode();
    for(int i=0;i<n;i++){
        cin>>str;
        insert(root,str);
    }
    
    for(int i=0;i<m;i++){
        cin>>str;
        cout<<search(root,str)<<"\n";
    }
    
    return 0;
}
