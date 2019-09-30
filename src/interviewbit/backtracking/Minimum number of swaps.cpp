#include<bits/stdc++.h>
#inlcude<vector>
#inlcude<set>
#inlcude<map>

using namespace std;

int solve(int A, vector<int> &B, vector<vector<int> > &C) {
    
    int cnt = 0,x=0,y;
    
    map<pair<int,int>, bool> req;
    unordered_map<int,int> index_map;
    unordered_map<int,int> t;

    for(int i = 0;i<B.size();i++)
        index_map[B[i]] = i;

    for(int i = 0;i<C.size();i++){
        req[{C[i][0],C[i][1]}] = true;
        t[C[i][0]] = C[i][1];
        t[C[i][1]] = C[i][0];
    }
    
    for(int i = 0;i<B.size();i+=2){
        if(req.count({B[i],B[i+1]}) > 0 || req.count({B[i+1],B[i]}) > 0){
            continue;
        }else{
            cnt++;
            x = i+1;
            y = index_map[t[B[i]]];
            index_map[B[i+1]] = y;
            index_map[B[index_map[t[B[i]]]]] = x;

            swap(B[x],B[y]);
        }
    }
    return cnt;
}

int main(){

    int A = 5;
    vector<int> B = { 10, 1, 7, 4, 6, 2, 3, 5, 8, 9};
    vector<vector<int>>C = {{6,7},{3,9},{2,5},{1,4},{8,10}}; 
    cout<<solve(A,B,C)<<"\n";
}

// int main(){

//     int A = 5;
//     vector<int> B = { 10, 1, 7, 4, 6, 2, 3, 5, 8, 9};
//     vector<vector<int>>C = {{6,7},{3,9},{2,5},{1,4},{8,10}}; 

//     cout<<solve(A,B,C)<<"\n";
// }
