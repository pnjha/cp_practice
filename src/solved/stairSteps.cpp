#include<bits/stdc++.h>

using namespace std;


int climbStairs(int n) {
        
    int s1 = 1;
    int s2 = 2;
    int s = 0;
        
    for(int i = 2;i<n;i++){
        
        s = s1 + s2;
        s1 = s2;
        s2 = s;
        
    }   
    return s;
}       

int main(){

    cout<<climbStairs(4)<<"\n";

    return 0;
}