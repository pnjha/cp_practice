#include<bits/stdc++.h>

using namespace std;

set<vector<string>> ans;

bool is_pallindrome(string& str,int left,int right){
    
    if(left == right)
        return true;
    
    for(int i = left,j = right;i<=j;i++,j--){
        if(str[i] != str[j]){
            return false;
        }
    }
    return true;
}

void dfs(string& str,int right, vector<string>& temp){
    
    if(right>=str.length()){
        ans.insert(temp);
        return;
    }
    
    // string s;
    
    for(int i = 1;i<str.length();i++){
        
        if(is_pallindrome(str,right,right+i-1)){
       
            temp.push_back({str.begin()+right,str.begin()+right+i});
            dfs(str,right+i,temp);
            temp.pop_back();
        }
        
    }
    
}


int main(){

	string s = "ccaacabacbccaacabacbccaacabacbccaacabacb";
    
    ans.clear();
    
    if(is_pallindrome(s,0,s.length()-1))
        ans.insert({s});

    vector<string> temp;
    
    dfs(s,0,temp);
    
    cout<<"#######################\n";

    vector<vector<string>> a = {ans.begin(),ans.end()};

    for(int i = 0;i<a.size();i++){

    	for(int j = 0;j<a[i].size();j++){

    		cout<<a[i][j]<<" ";

    	}
    	cout<<"\n";
    }

	return 0;
}
