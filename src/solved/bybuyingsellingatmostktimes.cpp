// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-
// a-share-at-most-k-times/
#include<bits/stdc++.h>

using namespace std;

int profitKTransaction(vector<int> &price,int k){

	vector<vector<int>> dp(k+1,vector<int>(price.size(),0));
	int maxDiff = INT_MIN;

	for(int i = 1;i<k+1;i++){
		maxDiff = INT_MIN;
		for(int j = 0;j<price.size();j++){
			maxDiff = max(maxDiff,dp[i-1][j]-price[j]);
			dp[i][j] = max(dp[i][j-1],price[j]+maxDiff);
		}
	}

	return dp[k][price.size()-1];
}


int main(){

	vector<int> price{10, 22, 5, 75, 65, 80};
	int k = 2;

	cout<<profitKTransaction(price,k)<<"\n";

	return 0;
}