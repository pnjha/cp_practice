struct node* lcaUtil(struct node* root,int a,int b){
    
    if(!root)
        return NULL;
    
    if(root->val==a||root->val==b)
        return root;
    
    struct node* left = lcaUtil(root->left,a,b);
    struct node* right = lcaUtil(root->right,a,b);

    if(left&&right)
        return root;
    
    return left==NULL?right:left;
}

bool isPresent(struct node* A,int C){
    if(!A)
        return false;
        
    if(A->val==C)
        return true;
        
    return (isPresent(A->left,C)||isPresent(A->right,C));    
}

struct node* lcaBST(struct node* root, int a,int b){

    if(!root)
        return root;

    if(root->val>a&&root->val>b){
        lcaBST(root->left,a,b);
    }

    if(root->val<a&&root->val<b){
        lcaBST(root->right,a,b);
    }
    
    return root;
}

int lca(struct node* A, int B, int C) {
    
    if(!isPresent(A,B)||!isPresent(A,C))
        return -1;
    
    struct node* ans = lcaUtil(A,B,C);
    
    if(!ans)    
        return -1;


    return ans;
}
