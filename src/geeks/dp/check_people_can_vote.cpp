// https://www.geeksforgeeks.org/check-people-can-vote-two-machines/

#include<bits/stdc++.h>

using namespace std;

bool canVote(vector<int>& a, int x){

	int sum = 0;
	for(int i = 0;i<n;i++){
		sum += a[i];
	}

	vector<vector<int>> dp(a.size()+1,vector<int>(x+1,0));

	for(int i = 1;i<=a.size();i++){
		for(int j = 1;j<=x;j++){
			if(dp[i]<=j){
				dp[i][j] = max(a[i]+dp[i-1][j-a[i]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return ((sum - dp[a.size()][x])<=x);
}

int main(){

	int n = 3, x = 4; 
    vector<int> a = {2, 4, 2}; 
    canVote(a, n, x)? cout << "YES\n" : cout << "NO\n"; 

	return 0;
}
