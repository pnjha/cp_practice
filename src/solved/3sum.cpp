#include <bits/stdc++.h>

using namespace  std;

int threeSumClosest(vector<int> &A, int B) {
    
    int diff = INT_MAX,sum = 0,left,right,a,b,c;

    sort(A.begin(),A.end());    
    
    for(int i=0;i<A.size()-2;i++){
        
        left = i+1;
        right = A.size()-1;
        
        while(left<right){

            if(abs(B-(A[i] + A[left] + A[right]))<diff){
                diff = abs(B-(A[i] + A[left] + A[right]));
                sum = (A[i] + A[left] + A[right]);
                a = A[i];
                b = A[left];
                c = A[right];
    
            }
            if(A[i] + A[left] + A[right] == B){
    
                return B;
            }else if(A[i] + A[left] + A[right] < B){
                left++;
            }else{
                right--;
            }
        }
    }
    
    return sum;
}

int main(){

    vector<int> arr;
    
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(0);
    arr.push_back(-1);

    cout<<threeSumClosest(arr,20)<<"\n";

    return 0;
}

