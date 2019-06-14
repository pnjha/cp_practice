#include<bits/stdc++.h>

using namespace std;

int pow(int base, int expo, int m) {
    
    if(m==1) 
        return 0;
    
    long long int ans = 1, y = base%m;
    
    while(expo>0){
        if(expo&1)
         ans=((ans)*y)%m;
        y=(y*y)%m;
        
        expo=expo>>1;
    }
    if(ans<0){
        ans = (ans + m)%m;
        return ans;
    }
    return (int)(ans%m);
}

double myPow(double x, int n) {
    double ans = 1.0;
    
    bool flag = false;
    
    if(n==0)
        return 1.0;
    else if(n<0){
        x = (1/x);
        n *= -1;
    }else if(n==1)
        return x;
    
    while(n>0){
        // cout<<ans<<" "<<x<<"\n";
        if(n&1)
            ans = ans * x;

        x = x*x;    
        n = n >> 1;
    }

    return ans;
}

int power(int x, unsigned int y) 
{ 
    int res = 1;     

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 

        // n must be even now 
        y = y>>1; // y = y/2 
        x = x*x; // Change x to x^2 
    } 
    return res; 
}

int main(){

    cout<<myPow(2.0,-2)<<"\n";
    cout<<power(2,10)<<"\n";
    return 0;
}