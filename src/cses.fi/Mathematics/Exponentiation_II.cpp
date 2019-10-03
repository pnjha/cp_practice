// https://cses.fi/problemset/task/1712

#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;

ll expo_iterative(ll a,ll b, ll m){

	ll ans = 1; 

	a = a%m;

	while(b>0){

		if(b&1){
			ans = (a * ans)%m;
		}

		b = b>>1;
		a = (a * a)%m;
	}

	return (ans)%m;
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ios_base::sync_with_stdio(NULL);

	ll t,a,b,c;
	cin>>t;

	while(t--){

		cin>>a>>b>>c;
		cout<<expo_iterative(a,(expo_iterative(b,c,MOD-1)),MOD)<<"\n";
	}

	return 0;
}
