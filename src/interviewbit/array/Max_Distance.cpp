// https://www.interviewbit.com/problems/max-distance/

#include<bits/stdc++.h>

using namespace std;


int maximumGap(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1)
        return -1;
    
    vector<int> lis(n+1,INT_MAX);
    int len = 0;
    pair<int,int> max_pair = {-1,-1};
    
    for(int i = 0;i<n;i++){
        
        for(int j = 0;j<lis.size();j++)
            cout<<lis[j]<<" ";
        cout<<"\n";

        int left = 1,right = len, mid = 0;
        
        while(left<=right){
            mid = left + (right-left)/2;
            if(A[lis[mid]]<=A[i]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        lis[left] = i;
        if(left>len)
            len = left;
    }
    
    return len;

    // int max_ele = INT_MIN, max_index;
    
    // for(int i = max_pair.first+1;i<n;i++){
    //     if(max_ele<A[i]){
    //         max_ele = A[i];
    //         max_index = i;
    //     }
    // }
    // if(max_ele == INT_MIN)
    //     return -1;
    // return (max_index - max_pair.first);
}

int main(){

    freopen("input.txt","r",stdin);

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++)
        cin>>arr[i];

    cout<<maximumGap(arr)<<"\n";

    return 0;
}
