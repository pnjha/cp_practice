#include<bits/stdc++.h>

using namespace std;

void generate_squences(vector<pair<int,int>> path_info, vector<vector<int>> &indexes,
                       vector<vector<int>> &lcs,vector<int> temp_index,string s1, string s2,int row, int col){
    
    cout<<"size: "<<temp_index.size()<<" \n";
    for(int i = 0;i<temp_index.size();i++)
        cout<<temp_index[i]<<" ";
    cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";


    if(temp_index.size()==s1.length()){
    
        reverse(temp_index.begin(),temp_index.end());
        indexes.push_back(temp_index);
    
        // for(int i = 0;i<path_info.size();i++){
        //     cout<<path_info[i].first<<" "<<path_info[i].second<<"\n";
        // }
        // cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        return;
    }
                                                                                //0 1 2 3 4 5 
    // if(s1[row-1] == s2[col-1]){                                                 //  a b c d e
        // cout<<s1[row-1]<<" "<<s2[col-1]<<"\n";
        // path_info.push_back({row,col});
    // }
    
    if(row>=1 && col>=1 && s1[row-1] == s2[col-1]){
        // cout<<row-1<<" "<<col-1<<" "<<s1[row-1]<<" "<<s2[col-1]<<"\n";
        temp_index.push_back(col-1);
        generate_squences(path_info,indexes,lcs,temp_index,s1,s2,row-1,col-1);
    }
    
    if(temp_index.size()>0)
        temp_index.pop_back();

    if(row>=1 && lcs[row][col] == lcs[row-1][col]){
        // path_info.push_back({row-1,col});
        generate_squences(path_info,indexes,lcs,temp_index,s1,s2,row-1,col);
    }
    
    if(col>=1 && lcs[row][col] == lcs[row][col-1]){
        // path_info.push_back({row,col-1});
        generate_squences(path_info,indexes,lcs,temp_index,s1,s2,row,col-1);
    }
    

}

bool modified_lcs(vector<vector<int>> &indexes, string s1, string s2){
    
    vector<vector<int>> lcs(s1.length()+1, vector<int>(s2.length()+1,0));
    
    for(int i = 1;i<lcs.size();i++){
        for(int j = 1;j<lcs[0].size();j++){
            if(s1[i-1] == s2[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    
    for(int i = 0;i<lcs.size();i++){
        for(int j = 0;j<lcs[0].size();j++){
            cout<<lcs[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<"\n";

    if(lcs[lcs.size()-1][lcs[0].size()-1]!=s1.length())
        return false;
    
    vector<int> temp_index;
    vector<pair<int,int>> path_info;
    
    // for(int i = lcs[0].size()-1;i>=1;i--){
        
        // temp_index.clear();
        
        // if(s1[s1.length()-1] == s2[i-1] && lcs[lcs.size()-1][i] == s1.length()){
            
            // temp_index.push_back(i);
        
    generate_squences(path_info,indexes,lcs,temp_index,s1,s2,lcs.size()-1,lcs[0].size()-1);
            
        // } 
    // }
    
    
    return true;
}

bool isInterleave(string s1, string s2, string s3) {
    
    if(s1.length()+s2.length() != s3.length())
        return false;
    
    if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
        return true;
    
    vector<vector<int>> s1_indexes, s2_indexes;
    
//         if(!modified_lcs(s1_indexes,s1,s3))
//             return false;
        
//         if(!modified_lcs(s2_indexes,s2,s3))
//             return false;
    
    bool flag = modified_lcs(s1_indexes, s1, s3);

    cout<<s3<<" "<<s1<<"\n";

    for(int i = 0;i<s1_indexes.size();i++){
        for(int j = 0;j<s1_indexes[0].size();j++){
            cout<<s1[s1_indexes[i][j]]<<" ";
        }
        cout<<"\n";
    }
    
    return true;
}

int main(){

    string s1,s2,s3;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";

    isInterleave(s1,s2,s3);

    return 0;
}