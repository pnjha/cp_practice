#include<bits/stdc++.h>

using namespace std;

vector<int> inorder(TreeNode* root){
    stack<TreeNode*> ele;
    TreeNode* curr = root;
    vector<int> ans;
    // ele.push(curr);
    
    while(curr!=NULL||ele.empty()==false){
         
        while(curr!= NULL){
            ele.push(curr);
            curr = curr->left;
        }
        
        curr = ele.top(); 
        ans.push_back(ele.top()->val);
        ele.pop();
        curr = curr->right;
    }
    return ans;
 }

 vector<int> preorder(TreeNode* root){
    stack<TreeNode*> ele;
    TreeNode* curr = root;
    vector<int> ans;
    // ele.push(curr);
    
    while(curr!=NULL||ele.empty()==false){
         
        while(curr!= NULL){
        	ans.push_back(curr->val);
            ele.push(curr);
            curr = curr->left;
        }
        
        curr = ele.top(); 
        // ans.push_back(ele.top()->val);
        ele.pop();
        curr = curr->right;
    }
    return ans;
 }
