// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
#include<bits/stdc++.h>

using namespace std;

int game_value(vector<int>& arr){

	int n = arr.size(),j,a,b;

	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));

	for(int i = 0;i<n;i++)
		dp[i][i] = {0,arr[i]};

	for(int l = 2;l<=n;l++){
		for(int i = 0;i<=(n-l);i++){
			j = i + l - 1;
			a = max(arr[i] + dp[i+1][j].first ,arr[j] + dp[i][j-1].first);
			if(a == arr[i] + dp[i+1][j].first){

				b = dp[i+1][j].second;

			}else if(a == arr[j] + dp[i][j-1].first){

				b = dp[i][j-1].second;
			}
			dp[i][j].second = a;
			dp[i][j].first = b;
		}
	}

	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
	// 	}cout<<"\n";
	// }

	return dp[0][n-1].second;
}

int main(){

	int t,n;
	cin>>t;

	vector<int> arr;

	while(t--){

		cin>>n;
		arr.clear();
		arr.resize(n,0);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<game_value(arr)<<"\n";
	}

	return 0;
}
