// min distance leaf from node k samsung 
void findLeafDown(Node *root, int lev, int *minDist) 
{ 
    // base case 
    if (root == NULL) 
        return ; 
  
    // If this is a leaf node, then check if it is closer 
    // than the closest so far 
    if (root->left == NULL && root->right == NULL) 
    { 
        if (lev < (*minDist)) 
            *minDist = lev; 
        return; 
    } 
  
    // Recur for left and right subtrees 
    findLeafDown(root->left, lev+1, minDist); 
    findLeafDown(root->right, lev+1, minDist); 
} 
int findThroughParent(Node * root, Node *x, int *minDist) 
{ 
    if (root == NULL) return -1; 
    if (root == x) return 0; 
  
    int l = findThroughParent(root->left, x,  minDist); 
  
    if (l != -1) 
    { 
        findLeafDown(root->right, l+2, minDist); 
        return l+1; 
    } 
  
    int r = findThroughParent(root->right, x, minDist); 
  
    if (r != -1) 
    { 
        findLeafDown(root->left, r+2, minDist); 
        return r+1; 
    } 
  
    return -1; 
} 
  
int minimumDistance(Node *root, Node *x) 
{ 
    int minDist = INT_MAX; 
    findLeafDown(x, 0, &minDist); 
    findThroughParent(root, x, &minDist);   
    return minDist; 
} 