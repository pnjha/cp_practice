// https://cses.fi/problemset/task/1158
//0/1 knapsack

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,x,a,b;

	cin>>n>>x;

	vector<ll> weight(n,0);
	vector<ll> profit(n,0);

	for(int i = 0;i<n;i++) cin>>weight[i];
	for(int i = 0;i<n;i++) cin>>profit[i];

	// vector<vector<ll>> dp(n+1,vector<ll>(x+1,0));

	vector<ll> prev(x+1,0);
	vector<ll> curr(x+1,0);

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=x;j++){
			curr[j] = max(prev[j], (j-weight[i-1]>=0)?prev[j-weight[i-1]]+profit[i-1]:0);
		}
		prev = curr;
		curr.clear();
		curr.resize(x+1,0);
	}

	cout<<prev[x]<<"\n";

	return 0;
}