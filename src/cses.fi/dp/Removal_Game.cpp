//stones removal game

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

/*
vector<vector<ll>> dp;

ll removal_game(vector<ll>& arr,int start,int end){

	if(start>end)
		return 0;

	if(start == end)
		return arr[start];

	if(dp[start][end]!=-1)
		return dp[start][end];

	ll a = min(removal_game(arr,start+2,end),removal_game(arr,start+1,end-1));
	ll b = min(removal_game(arr,start,end-2),removal_game(arr,start+1,end-1));

	return dp[start][end] = max(a+arr[start],b+arr[end]);
}
*/


ll removal_game(vector<ll>& arr,int start,int end,int player){

	ll n = arr.size();

	vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(n,{0,0}));

	for(int i = 0;i<n;i++)
		dp[i][i] = {arr[i],0};

	for(int l = 2;l<=n;l++){
		for(int i = 0;i<=(n-l);i++){
			int j = i+l-1;
			if(dp[i+1][j].second+dp[i][i].first > dp[i][j-1].second+dp[j][j].first){
				dp[i][j].first = dp[i+1][j].second+dp[i][i].first;
				dp[i][j].second = dp[i+1][j].first;
			}else{
				dp[i][j].first = dp[i][j-1].second+dp[j][j].first;
				dp[i][j].second = dp[i][j-1].first;
			}
		}
	}

	// for(int i = 0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	return dp[0][n-1].first;
}

int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	ll n;
	cin>>n;

	vector<ll> arr(n,0);

	// dp.clear();
	// dp.resize(n,vector<vector<ll>>(n,vector<ll>(2,-1)));

	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	cout<<removal_game(arr,0,n-1,0)<<"\n";

	return 0;
}
