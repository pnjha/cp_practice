// https://cses.fi/problemset/task/1646
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	// freopen("in","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,l,r,ans;
	cin>>n>>q;

	vector<ll> arr(n);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(i>0) arr[i] += arr[i-1]; 
	}

	for(int i = 0;i<q;i++){
		cin>>l>>r;
		l--,r--;
		if(l==0) ans = arr[r];
		else ans = arr[r] - arr[l-1];
		cout<<ans<<"\n";
	}

	return 0;
}
