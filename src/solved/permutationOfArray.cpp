#include<bits/stdc++.h>

using namespace std;


void permutation(vector<int> &num, int start, vector<vector<int> > &result) {
    if(start == num.size() - 1){
        result.push_back(num);
        return;
    } 
    for(int i = start;i < num.size();i++){
        swap(num[start], num[i]);
        permutation(num, start + 1, result);
        swap(num[start], num[i]);
    }
}


vector<vector<int>> permute(vector<int> &A) {
    vector<vector<int> > result;
    if (A.size() == 0)
        return result;
    sort(A.begin(), A.end());
    permutation(A, 0, result);
    return result;
}

int main(){

    return 0;
}