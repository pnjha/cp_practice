// https://www.spoj.com/problems/MIXTURES/

#include<bits/stdc++.h>
#define int long long 
using namespace std;

int min_smog(vector<int>& arr){

	int n = arr.size();

	if(n == 1)
		return 0;

	//color smoke
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));

	for(int i = 0;i<n;i++){
		dp[i][i] = {arr[i],0};
	}

	for(int l = 2;l<=n;l++){

		for(int i = 0;i<=(n-l);i++){

			int j = i + l - 1, smoke = INT_MAX, color = -1;

			for(int k = i;k<j;k++){

				if(smoke > (dp[i][k].second + dp[k+1][j].second + (dp[i][k].first * dp[k+1][j].first))){
					smoke = dp[i][k].second + dp[k+1][j].second + (dp[i][k].first * dp[k+1][j].first);
					color = (dp[i][k].first + dp[k+1][j].first)%100;
				}
			}
			dp[i][j].first = color;
			dp[i][j].second = smoke;
		}
	}

	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout<<dp[i][j].first<<" "<<dp[i][j].second<<" | ";
	// 	}cout<<"\n";
	// }

	return dp[0][n-1].second;
}

int32_t main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n;
	vector<int> arr;

	while(scanf("%lld",&n)==1){

		arr.clear();
		arr.resize(n,0);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<min_smog(arr)<<"\n";
	}

	return 0;
}

/*
5535
4310
13997
6159
3037
17569
9581
20035
21575
6319
4760
14189
2753
5752
19037
10205
624
17936
23862
2669
19721
1116
*/