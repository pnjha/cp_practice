// https://codeforces.com/contest/1248/problem/A
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	ll t,n,m,e,o;
	cin>>t;

	while(t--){

		cin>>n;
		vector<ll> a(n);
		for(int i = 0;i<n;i++) cin>>a[i];
		cin>>m;
		vector<ll> b(m);
		for(int i = 0;i<m;i++) cin>>b[i];

		e=0,o=0;
		for(int i = 0;i<n;i++){
			if(abs(a[i])%2==0) o++;
			else e++;
		}

		ll ans = 0;
		for(int i = 0;i<m;i++){
			if(abs(b[i])%2==0) ans += o;
			else ans += e;
		}

		cout<<ans<<"\n";
	}

	return 0;
}
