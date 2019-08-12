#include<bits/stdc++.h>

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
            // cout<<(i+1)<<" "<<
        }
        // for(int i = 0;i<B.size();i++)
        //     cout<<B[i]<<" ";
        // cout<<"\n";
    }


    return cnt;
}

int main(){

    int A = 5;
    vector<int> B = { 10, 1, 7, 4, 6, 2, 3, 5, 8, 9};
    vector<vector<int>>C = {{6,7},{3,9},{2,5},{1,4},{8,10}}; 
    cout<<solve(A,B,C)<<"\n";
}


// int solve(int A, vector<int> &B, vector<vector<int> > &C) {
    
//     int cnt = 0,x,y;
    
//     map<pair<int,int>, bool> req;
//     unordered_map<int,int> t;
//     unordered_map<int,int> index_map;
    
//     for(int i = 0;i<B.size();i++)
//         index_map[B[i]] = i;
    
//     for(int i = 0;i<C.size();i++){
//         req[{C[i][0],C[i][1]}] = true;
//         t[C[i][0]] = C[i][1];
//         t[C[i][1]] = C[i][0];
//     }
        
//     queue<pair<vector<int>,int>> q;
//     bool flag = true;
//     vector<int> temp,temp2;
//     pair<vector<int>,int> p;
    
//     q.push({B,0});
    
//     while(!q.empty()){
        
//         flag = true;
//         p = q.front();    
//         temp = p.first;
//         q.pop();
        
//         cout<<p.second<<"\n";

//         for(int i = 0;i<temp.size();i+=2){
//             for(int i = 0;i<temp.size();i++)
//                 cout<<temp[i]<<" ";
//             cout<<"\n";
//             if(req.count({temp[i],temp[i+1]}) == 0 && req.count({temp[i+1],temp[i]}) == 0){
//                 flag = false;
//                 break;
//             }
//         }

//         if(flag){
//             cnt = p.second;
//             for(int i = 0;i<temp.size();i++)
//                 cout<<temp[i]<<" ";
//             cout<<"\n";
//             break;
//         }

//         temp2 = temp;
        
//         x = t[p.second*2+1];
//         temp2[index_map[t[p.second*2+1]]] = temp[p.second*2];
//         temp2[p.second*2] = x;
        
//         q.push({temp2,p.second+1});
        
//         temp2 = temp;
//         x = t[p.second*2];
//         temp2[index_map[t[p.second*2]]] = temp[p.second*2+1];
//         temp2[p.second*2+1] = x;
        
//         q.push({temp2,p.second+1});
//     }
    
//     return cnt;
// }

// int main(){

//     int A = 5;
//     vector<int> B = { 10, 1, 7, 4, 6, 2, 3, 5, 8, 9};
//     vector<vector<int>>C = {{6,7},{3,9},{2,5},{1,4},{8,10}}; 

//     cout<<solve(A,B,C)<<"\n";
// }