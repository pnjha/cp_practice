// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int dp[107][100009];

ll dfs(vector<ll> &a, int idx, ll val, ll b){
	// cout<<idx<<" "<<val<<" "<<b<<"\n";
	if(idx >= a.size()) return 0;
	if(dp[idx][val]!=-1) return dp[idx][val];

	ll x = dfs(a,idx+1,val,b);

	if(val + a[idx] > b) return x;

	ll y = dfs(a,idx+1,val+a[idx],b);
	dp[idx][val] = max(x,y+1);
	return dp[idx][val];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	int t;
	cin>>t;

	for(int i = 1;i<=t;i++){

		memset(dp,-1,sizeof(dp));

		ll ans = 0;
		ll n,b;
		cin>>n>>b;
		vector<ll> a(n,0);

		for(int i = 0;i<n;i++){
			cin>>a[i];
		}

		vector<ll> dp(b+1,0);

		ans = dfs(a,0,0,b);

		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}


	return 0;
}
