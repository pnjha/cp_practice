#include<bits/stdc++.h>

using namespace std;

unordered_map<int,int> memo;

int dfs(vector<int>&arr, int index, int sum){

	if(memo.find(sum) != memo.end())
		return memo[sum];

	if(sum == 0){
		return 1;
	}

	if(sum<0)
		return 0;

	int cnt = 0;

	for(int i = 0;i<arr.size();i++){

		cnt += dfs(arr,i,sum-arr[i]);
	}	

	memo[sum] = cnt;
}

int main(){

	freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	memo.clear();

	int n,x;
	cin>>n>>x;

	vector<int> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	int cnt = 0;

	for(int i = 0;i<arr.size();i++){

		// if(memo.find(arr[i]) == memo.end()){

			cnt += dfs(arr,i,x-arr[i]);
			// cnt += memo[arr[i]];

		// }else{

		// 	cnt += memo[arr[i]];

		// }
	}

	cout<<cnt<<"\n";

	return 0;
}