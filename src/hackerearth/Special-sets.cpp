#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll npr(ll n, ll r){
	// if(n == r)
	// 	return 1;

	if(n<r)
		return 0;

	ll ans = 1;
	for(ll i = n;i>=n-r+1;i--)
		ans = (ans * i)%MOD;

	return ans;
}

int main(){

	ll n;
	cin>>n;

	if(n == 1){
		cout<<"1\n";
		return 0;
	}

	int ans = 0;

	for(int i = 1;i<n;i++){
		// cout<<n-i+1<<" "<<i<<" "<<npr(n-i+1,i)<<"\n";
		ans = (ans + npr(n-i+1,i))%MOD;
	}

	cout<<ans<<"\n";

	return 0;
}
