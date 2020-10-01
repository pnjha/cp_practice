#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll l,r;
    cin >> l >> r;
    r=min(r,l+2019);
  
    ll res = 2018;
    for (ll i = l; i <= r; ++i)
    {
        for (ll j = i + 1; j <= r; ++j)
        {
            res = min(res, (i * j) % 2019);
        }
    }
    cout<<res;
}