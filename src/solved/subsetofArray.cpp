//lexicographically sorted non duplicate list of subsets

vector<vector<int>> ans;

void permuteRec(vector<int> num,int index, vector<int> curr){ 
    
    if (index == num.size()) 
        return; 
    if(find(ans.begin(),ans.end(),curr)==ans.end())
        ans.push_back(curr);

    for(int i = index + 1; i < num.size(); i++) { 

        curr.push_back(num[i]); 
        permuteRec(num,i,curr); 
        curr.resize(curr.size() - 1); 
    } 
    return; 
} 

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A) {
    
    sort(A.begin(),A.end());
    ans.clear();
    vector<int> temp;
    permuteRec(A,-1,temp);
    
    return ans;
}
