#include<bits/stdc++.h>
#define len 4
using namespace std;

int searchInsert(vector<int> &A, int B) {
    
    int low = 0, high = A.size()-1, mid = 0;
    bool flag = false;
    
    while(low<high){

        mid = ceil((low+high)/2);
        
        if(A[mid] == B){
            return mid;   
        }else if(A[mid]>B){
            high = mid-1;
        }else if(A[mid]<B){
            low = mid+1;
        }
        
    }
    
    if(A[0]>B)
        return 0;
    else if(A[A.size()-1]<B)
        return A.size();
}

int main(){

    vector<int> arr;

    arr.push_back(1);
    cout<<searchInsert(arr,1)<<"\n";

    return 0;
}