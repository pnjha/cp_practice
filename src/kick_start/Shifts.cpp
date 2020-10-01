// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fd5e

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a,b;
// map<ll,map<ll,map<ll,ll>>> dp;
map<>

ll dfs(ll as,ll bs, ll pos, ll h, ll n){

	if(pos == n){
		if(as >= h && bs >= h) {

			return 1;
		}
		else return 0;
	}

	// if(dp.find(pos)!=dp.end()){
	// 	if(dp[pos].find(as)!=dp[pos].end()){
	// 		if(dp[pos][as].find(bs)!=dp[pos][as].end()){
	// 			return dp[pos][as][bs];
	// 		}		
	// 	}
	// }

	ll ans = 0;
	ans += dfs(as+a[pos],bs,pos+1,h,n);
	ans += dfs(as,bs+b[pos],pos+1,h,n);
	ans += dfs(as+a[pos],bs+b[pos],pos+1,h,n);

	// dp[pos][as][bs] = ans;

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t,n,h,q;
	cin>>t;

	for(int k = 1;k<=t;k++){

		dp.clear();
		cin>>n>>h;
		a.clear(),b.clear();
		a.resize(n), b.resize(n);

		for(int i = 0;i<n;i++) cin>>a[i];
		for(int i = 0;i<n;i++) cin>>b[i];

		ll ans = dfs(0,0,0,h,n);

		cout <<"Case #" << k <<": "<<ans<<"\n";
	}

	return 0;
}
