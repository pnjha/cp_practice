#include<bits/stdc++.h>
#define SIZE 107
using namespace std;

int mcmrec(vector<int>& arr, int left, int right){

	if(left == right)
		return 0;

	int ans = INT_MAX, temp = 0;

	for(int k = left;k<right;k++){

		temp = mcmrec(arr,left,k) + mcmrec(arr,k+1,right) + arr[left-1]*arr[k]*arr[right]; 
		ans = min(ans, temp);
	}

	return ans;
}

int tpdp[SIZE][SIZE] = {-1};

int mcmtd(vector<int>& arr, int left, int right){

	if(left == right){
		tpdp[left][right] = 0;
		return 0;
	}

	if(tpdp[left][right] != -1)
		return tpdp[left][right];

	int ans = INT_MAX, temp = 0;

	for(int k = left;k<right;k++){

		temp = mcmrec(arr,left,k) + mcmrec(arr,k+1,right) + arr[left-1]*arr[k]*arr[right]; 
		ans = min(ans, temp);
	}

	tpdp[left][right] = ans;

	return ans;
}

int mcmbu(vector<int>& arr){

	int n = arr.size();

	vector<vector<int>> dp(n,vector<int>(n,0));

	for(int l = 2;l<=n;l++){

		for(int i = 0;i<=(n-l);i++){

			int j = i + l - 1;

			dp[i][j] = INT_MAX;

			for(int k = i;k<j;k++){

				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
			}
		}

	}


	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }

	return dp[1][n-1]; 
}

int main(){

	vector<int> arr = {1,2,3,4};

	cout<<mcmrec(arr,1,arr.size()-1)<<"\n";

	memset(tpdp,-1,sizeof tpdp);
	cout<<mcmtd(arr,1,arr.size()-1)<<"\n";

	cout<<mcmbu(arr)<<"\n";

	return 0;
}
