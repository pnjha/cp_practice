// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
 
#include<bits/stdc++.h>
 
using namespace std;
 
int k_order_lcs(vector<int>& seq1,vector<int>& seq2,int k){
 
	int n = seq1.size(),m = seq2.size();
 
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));
 
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			for(int l = 1;l<=k;l++){
				if(seq1[i-1] == seq2[j-1]){
					dp[i][j][l] = 1 + dp[i-1][j-1][l];
				}else{
					dp[i][j][l] = max(dp[i-1][j][l],max(dp[i][j-1][l],(1+dp[i-1][j-1][l-1])));
				}
			}
		}
	}
 
	return dp[n][m][k];
}
 
int main(){
 
	int n,m,k;
	cin>>n>>m>>k;
 
	vector<int> seq1(n),seq2(m);
 
	for(int i = 0;i<n;i++){
		cin>>seq1[i];
	}
 
	for(int i = 0;i<n;i++){
		cin>>seq2[i];
	}
 
	cout<<k_order_lcs(seq1,seq2,k)<<"\n";
 
	return 0;
}