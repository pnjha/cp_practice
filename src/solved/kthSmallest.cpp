//using kinorder traversal. O(n) time complexity and 
//O(1) space complexity

TreeNode* temp = NULL;

void inOrder(TreeNode* root,int k,int &count){
    
    if(root)
    {
        inOrder(root->left,k,count);
    
        count++;
        
        if(count==k){
            temp = root;
            return;
        }
        
        inOrder(root->right,k,count);
    }    
} 

int kthsmallest(TreeNode* A, int B) {
    int count = 0;
    inOrder(A,B,count);
    return temp->val;
}