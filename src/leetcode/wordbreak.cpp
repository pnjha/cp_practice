#include<bits/stdc++.h>

using namespace std;

   
// unordered_map<string,bool> dictionary;
// unordered_map<int,vector<int>> dp;

// bool dfs(string& s,int index){
//     cout<<index<<"\n";
//     if(index>=s.length())
//         return true;
    
//     if(dp[index].size()==0)
//         return dfs(s,index+1);
    
//     for(int i = 0;i<dp[index].size();i++){
//         if(dfs(s,dp[index][i]+1))
//             return true;
//     }
    
//     return false;
// }

// bool wordBreak(string s, vector<string>& wordDict) {
    
//     std::ios_base::sync_with_stdio(false);
    
//     dictionary.clear();
//     dp.clear();
    
//     bool flag = false;
//     string t;
    
//     for(int i = 0;i<wordDict.size();i++){
//         dictionary[wordDict[i]] = true;
//     }
    
//     if(s.length()==1){
//         if(dictionary[s]==1){
//             return true;
//         }
//     }
    
    
//     for(int i = 0;i<s.length();i++){
//         for(int j = i;j<s.length();j++){
//             if(dictionary[s.substr(i,j-i+1)]){
//                 dp[i].push_back(j);                      
//             }
//         }
//         sort(dp[i].begin(),dp[i].end(),greater<int>());
//     }
    
//     for(int i = 0;i<s.length();i++){
//         cout<<i<<" : ";
//         for(int j = 0;j<dp[i].size();j++)
//             cout<<dp[i][j]<<" ";
//         cout<<"\n";
//     }
    
//     if(dp[0].size()==0)
//         return false;
    
//     int max_val = INT_MIN;    
    
//     for(int i = 0;i<dp.size();i++){
//         if(max_val!=INT_MIN){
//             if(max_val>=s.length())
//                 return true;
//         }
//         if(i!=0){
//             if(dp[i].size()==0){
//                 if(max_val<i){
//                     // cout<<"here\n";
//                     return false;
//                 }
//             }
//         }
//         for(int j = 0;j<dp[i].size();j++){
//             if(max_val<dp[i][j])
//                 max_val = dp[i][j];
//         }
//     }

//     for(int i = 0;i<dp[0].size();i++){
        
//         flag = dfs(s,dp[0][i]+1);
//         if(flag)
//             return true;
//     }
    
//     return flag;
// }


// unordered_map<string,bool> dictionary;
unordered_map<string,vector<string>> dp;

bool starts_with(string s,string dict_word){
    // cout<<"starts_with: "<<s.substr(0,dict_word.length())<<"  "<<dict_word<<"\n";
    if(s.substr(0,dict_word.length())==dict_word){
        return true;
    }
    return false;
}

void dfs(string s, vector<string>& dict,vector<string>& temp){
    // cout<<s<<" \n";
    if(dp[s].size()!=0){
        temp = dp[s];
        return;
    }
    // cout<<"here\n";
    
    vector<string> t;
    
    for(int i = 0;i<dict.size();i++){
        if(starts_with(s,dict[i])){
            // cout<<"entered\n";
            // cout<<s<<" "<<dict[i]<<"\n";
            if(s.length() == dict[i].length()){
                
                temp.push_back(dict[i]);
                
            }else{
                
                dfs(s.substr(dict[i].length(),s.length()-dict[i].length()),dict,t);
                
                for(int j = 0;j<t.size();j++){
                    
                    temp.push_back(dict[i] + " " + t[j]);
                    
                }
                
            }
            
        }
        
    }
    
    dp[s] = temp;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    
    vector<string> ans;
    
    dp.clear();
            
    dfs(s,wordDict,ans);

    return ans;
}

int main(){

    // std::ios_base::sync_with_stdio(false);
    string s;
    // vector<string> wordDict{"a","aab","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    // s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // vector<string> wordDict{"cats","dog","sand","and","cat"};
    // s = "catsandog";
    vector<string> wordDict{"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    vector<string> ans;

    cout<<s.length()<<"\n";
    ans = wordBreak(s,wordDict);
    cout<<"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ\n";
    for(int i = 0;i<ans.size();i++){
        
        cout<<ans[i]<<" \n";
    }

    return 0;
}




