#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* search_node(TreeNode* root, int val){
    if(!root)
        return NULL;
    
    if(root->left && root->left->val == val)
        return root;
    
    if(root->right && root->right->val == val)
        return root;
    
    TreeNode* left = search_node(root->left,val);
    TreeNode* right = search_node(root->right,val);

    if(!left)
        return right;
    
    return left;
}
    
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
    
    unordered_set<TreeNode*> root_list;

    root_list.insert(root);
  
    TreeNode* node = nullptr, *del_node = nullptr;
    
    for(int i = 0;i<to_delete.size();i++){
        
        node = nullptr;
        
        for(auto root:root_list){
            node = search_node(root,to_delete[i]);
            if(node)
                break;
        }
        
        if(!node)
            continue;
        
        if(node->left && node->left->val == to_delete[i]){
            del_node = node->left;
            node->left = nullptr;
        }else if(node->right && node->right->val == to_delete[i]){
            del_node = node->right;
            node->right = nullptr;
        }
        
        if(root_list.find(del_node)!=root_list.end())
            root_list.erase(del_node);
        
        if(del_node->left)
            root_list.insert(del_node->left);
        
        if(del_node->right)
            root_list.insert(del_node->right);
   
        del_node->left = nullptr;
        del_node->right = nullptr;
        
        free(del_node);
    }

    return {root_list.begin(),root_list.end()};
}

int main(){

	return 0;
}