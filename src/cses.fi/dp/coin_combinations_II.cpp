#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x;
	cin>>n>>x;

	vector<int> coins(n);

	for(int i = 0;i<n;i++)
		cin>>coins[i];

	vector<int> dp(x+1,0);
	
	dp[0] = 1;

	sort(coins.begin(),coins.end());

	for(int i = 0;i<coins.size();i++){

		for(int j = 1;j<dp.size();j++){

			if(j == coins[i])
				dp[j] += 1;
			
			else if(j>coins[i]){

				dp[j] = (dp[j]%MOD + dp[j-coins[i]]%MOD)%MOD;
			}
		}

	}

	// for(int i = 0;i<dp.size();i++){

	// 	for(int j = 0;j<dp[0].size();j++){

	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// cout<<dp[dp.size()-1][dp[0].size()-1]<<"\n";

	cout<<dp.back()<<"\n";
	return 0;
}
