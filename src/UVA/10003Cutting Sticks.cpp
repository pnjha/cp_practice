#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>

using namespace std;

int dp[1007][1007] = {-1};

int dfs(vector<int>& arr, int start, int end, int l){


	if(start < 0 || end > l || start >= end)
		return 0;

	if(dp[start][end]!=-1)
		return dp[start][end];

	int cost = 0, min_cost = INT_MAX; 

	for(int i = 0;i<arr.size();i++){

		cost = -1;

		if(arr[i]<end && arr[i]>start){
			cost = dfs(arr,start,arr[i],l) + dfs(arr,arr[i],end,l) + (end - start);
		}

		if(cost!=-1 && cost < min_cost)
			min_cost = cost;
	}

	if(min_cost == INT_MAX){
		min_cost = 0;
	}

	dp[start][end] = min_cost;
	return min_cost;
}

int solve(int l,int n,vector<int>& arr){
	
	memset(dp,-1,sizeof dp);
	
	return dfs(arr,0,l,l);
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int l,n;
	vector<int> arr;

	while(true){

		cin>>l;
		
		if(l == 0)
			break;
		cin>>n;

		arr.resize(n);

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		cout<<"The minimum cutting is "<<solve(l,n,arr)<<".\n";

		arr.clear();
	}

	return 0;
}
