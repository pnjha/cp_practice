// https://online.codingblocks.com/player/33819/content/13675/5102

#include<bits/stdc++.h>
#define MOD 1000003

using namespace std;

int dp[2][103][103] = {0};

int t,n1,k1;

int dfs(int prev, int n, int k){

	// if(n == k+1)
	// 	return 2;
	if(n == 0){
		if(k == 0){
			return 1;
		}
		return 0;
	}
	
	if(k == 0){
		if(n>0)
			return 1;
	}

	// if(prev == 1 && k == 1 && n == 1)
	// 	return 1;
	
	// if(prev == 0 && n == 1)
	// 	return 0;

	if(dp[prev][n][k]!=-1)
		return dp[prev][n][k];

	int cnt = 0;


	if(prev == 0){
	
		cnt = (cnt + dfs(1,n-1,k))%MOD;
		// cnt = (cnt + dfs(1,n-1,k))%MOD;
	
	}else{

		cnt = (cnt + dfs(1,n-1,k-1))%MOD;
	}

	cnt = (cnt + dfs(0,n-1,k))%MOD;
	dp[prev][n][k] = cnt;

	return cnt;
}

int dfs2(int prev, int n, int k){

	// if(n == k+1)
	// 	return 2;
	if(n == n1){
		if(k == k1){
			return 1;
		}
		return 0;
	}

	if(dp[prev][n][k]!=-1)
		return dp[prev][n][k];

	int cnt = 0;

	if(prev == 0){
	
		cnt = (cnt + dfs2(1,n+1,k))%MOD;
	
	}else{

		cnt = (cnt + dfs2(1,n+1,k+1))%MOD;
	}

	cnt = (cnt + dfs2(0,n+1,k))%MOD;
	dp[prev][n][k] = cnt;

	return cnt;
}

int main(){


	cin>>t;

	while(t--){

		cin>>n1>>k1;
		
		memset(dp,-1,sizeof dp);

		cout<<(dfs(0,n1-1,k1)%MOD + dfs(1,n1-1,k1)%MOD)%MOD<<"\n";
		// cout<<(dfs2(0,1,0)%MOD + dfs2(1,1,0)%MOD)%MOD<<"\n";

	}

	return 0;
}
