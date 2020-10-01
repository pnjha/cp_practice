// m1.codeforces.com/contest/1283/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ll t,n,k;
	cin>>t;

	while(t--){

		cin>>n>>k;
		ll ans = (n - (n%k));
		if(n%k==0) ans = n;
		else{
			if((n%k)>(k/2)) ans += (k/2);
			else ans += n%k;
		}

		cout<<ans<<" \n";
	}

	return 0;
}
