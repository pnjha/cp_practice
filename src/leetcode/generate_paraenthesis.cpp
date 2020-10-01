#include <bits/stdc++.h>

using namespace std;


vector<string> ans;

unordered_map<string,bool> is_valid;
int count_occr = 0;

void dfs(string& temp,int left,int right){

    if(left<0||right<0)
        return;

    if(left>right)
        return;
    
    if(left==0&&right==0){
        
        if(is_valid.find(temp)==is_valid.end()){//&&check_valid_parenthesis(temp)){
            is_valid[temp] = true;
            cout<<temp<<"\n";
            ans.push_back(temp);
        }
        return;
    }
    
    temp += '(';
    dfs(temp,left-1,right);
    temp.pop_back();
    temp += ')';
    dfs(temp,left,right-1);
    temp.pop_back();
}

vector<string> generateParenthesis(int n) {

    ans.clear();
    is_valid.clear();
    
    if(n == 0)
        return ans;
    if(n == 1)
        return {"()"};
    
    string temp;

    temp = '(';
    dfs(temp,n-1,n);

    return ans;
}



int main(){

    // generateParenthesis(6);
    int count_occr = 0;
    for(auto x: generateParenthesis(7))
        count_occr++;
        // cout<<x<<"\n";
    cout<<count_occr<<"\n";
    return 0;
}




