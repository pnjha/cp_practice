#include<bits/stdc++.h>

using namespace std;

int main(){
    
    unsigned int A = 43261596;
    unsigned int ans = 0;
    unsigned int counter = sizeof(A) * 8; 
    
    while(A){
        cout<<counter<<" "<<ans<<" "<<A<<"\n";

        ans <<= 1;

        if(A&1){
            ans += 1;
        }
        
        A >>= 1;
        
        counter--;
    }
    
    cout<<A<<"\n";

    ans <<= counter;

    cout<<ans<<"\n";

    return 0;
}
