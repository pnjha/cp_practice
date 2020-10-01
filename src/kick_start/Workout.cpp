// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	int t;
	cin>>t;

	for(int i = 1;i<=t;i++){

		ll ans = 0;
		ll n,k;
		cin>>n>>k;

		vector<ll> a(n,0);
		vector<ll> d;

		for(int i = 0;i<n;i++) cin>>a[i];
		
		ll maxdiff = 0,idx = -1;	
		for(int i = 1;i<n;i++) {
			// cout<<a[i]<<"\n";
			d.push_back(a[i] - a[i-1]);
			// cout<<d[i-1]<<"\n";
		}
		
		sort(d.begin(),d.end());
		
		for(int i = 0;i<n;i++) cout<<d[i]<<" \n";

		if(d[n-1]%2==0) maxdiff = d[n-1]/2;
		else maxdiff = d[n-1]/2 + 1;
		
		maxdiff = max(maxdiff, d[n-2]);

		cout<<"Case #"<<i<<": "<<maxdiff<<"\n";
	}


	return 0;
}
