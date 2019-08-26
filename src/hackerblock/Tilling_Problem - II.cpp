#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int tilling_dp(int n,int m){

	vector<int> dp(n+1,1);

	for(int i = m;i < n+1;i++){

		dp[i] = (dp[i-1]%MOD + dp[i-m]%MOD)%MOD;		
	}

	return dp.back()%MOD;
}

int main(){

	int t,n,m;
	cin>>t;

	while(t--){

		cin>>n>>m;

		cout<<tilling_dp(n,m)%MOD<<"\n";

	}


	return 0;
}
