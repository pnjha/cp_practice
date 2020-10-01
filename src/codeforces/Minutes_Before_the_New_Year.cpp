// http://m1.codeforces.com/contest/1283/problem/A
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ll t, h,m;
	cin>>t;
	while(t--){
		cin>>h>>m;
		ll ans = (23-h)*60 + 60 - m;
		cout<<ans<<" \n";
	}

	return 0;
}
