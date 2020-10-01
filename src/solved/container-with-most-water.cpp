#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &A) {
    
    int max = INT_MIN,msf = INT_MIN,m;
    int left,right,temp;
    
    for(int i=0;i<A.size();i++){
        
        left = i-1;
        right = i+1;
        
        // cout<<"msf: "<<msf<<"\n";

        while(left>=0){
            temp = A[left]<A[i]?A[left]:A[i];
            if(temp*(abs(left-i))>max)
                max = temp*(abs(left-i));
            
            left--;
        }
        
        // cout<<"Max left: "<<max<<"\n";

        if(max!=INT_MIN)
            m = max;
        else
            m = 0;    
        
        max = INT_MIN;


        
        while(right<A.size()){
            temp = A[right]<A[i]?A[right]:A[i];
            if(temp*(abs(right-i))>max)
                max = temp*(abs(right-i));
            
            right++;    
        }
        
        // cout<<"Max right: "<<max<<"\n";

        if(max>m)
            m = max;
            
        max = INT_MIN;
        
        if(m>msf)
            msf = m;
        m = 0;
    }
    return msf;
}

int main(){

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);

    cout<<maxArea(arr)<<"\n";

    return 0;
}

