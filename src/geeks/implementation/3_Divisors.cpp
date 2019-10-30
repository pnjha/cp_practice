// https://practice.geeksforgeeks.org/problems/3-divisors/0/?ref=self
#include <bits/stdc++.h>
#define ll long long int
#define MAXVAL 1e7+5
using namespace std;
vector<ll> primes;

void seive(ll max_val){
    vector<bool> is_prime(max_val,true);
    is_prime[0] = false, is_prime[1] = false;
    for(int i = 2;i<max_val;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]*i<max_val;j++)
            is_prime[primes[j]*i] = false;
    }
}

int main() {
    seive(MAXVAL);
    ll t,n,ans=0;
    cin>>t;
    
    while(t--){
        cin>>n;
        ans=0;
        for(int i = 0;primes[i]*primes[i]<=n;i++) ans++;
        cout<<ans<<"\n";
    }
    
    return 0;
}