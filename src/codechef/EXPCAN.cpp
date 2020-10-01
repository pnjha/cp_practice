// https://www.codechef.com/AM19MOS/problems/EXPCAN
#include<bits/stdc++.h>

using namespace std;

long double dp[1007][1007];

long double dfs(vector<long double>& arr,int l,int r){
	if(l>r || l<0 || r<0 || r>=arr.size() || l>=arr.size()) return 0.0;
	if(dp[l][r]!=-1.0) return dp[l][r];
	long double left = arr[l] + 0.5*(dfs(arr,l+1,r-1)+dfs(arr,l+2,r));
	long double right = arr[r] + 0.5*(dfs(arr,l+1,r-1)+dfs(arr,l,r-2));
	dp[l][r] = 0.5*(left+right);
	return dp[l][r];
}

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		for(int i = 0;i<1007;i++){
			for(int j = 0;j<1007;j++){
				dp[i][j] = -1.0;
			}
		}
		int n;
		cin>>n;
		vector<long double> arr(n,0.0);
		for(int i = 0;i<n;i++) cin>>arr[i];
		cout<<fixed<<setprecision(15)<<dfs(arr,0,n-1)<<"\n";
	}

	return 0;
}


/*
2
2
1 2
3
1 2 3
*/