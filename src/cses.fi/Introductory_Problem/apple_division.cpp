#include<bits/stdc++.h>

using namespace std;

long long int diff = INT_MAX;

void dfs(vector<long long int> arr, long long int left, long long int right, long long int index){

	if(index == arr.size()){
		if(abs(left-right)<diff)
			diff = abs(left-right);
		return;
	}

	dfs(arr,left+arr[index],right,index+1);
	dfs(arr,left,right+arr[index],index+1);	
}

void subset_sum(vector<long long int> arr, long long int target,long long int sum){

	// vector<vector<long long int>> dp(arr.size()+1,vector<long long int>(target+1,0));	

	vector<int> prev(target+1,0);
	vector<int> present(target+1,0);

	// sort(arr.begin(),arr.end());

	int max_val = INT_MIN;

	for(int i = 1;i<arr.size()+1;i++){

		for(int j = 1;j<present.size();j++){

			if(j < arr[i-1])	
				present[j] = prev[j];
			else if(j == arr[i-1]){
				present[j] = j;
			}else{
				if(prev[j-arr[i-1]]!=0){
					present[j] = j;
				}else{
					present[j] = prev[j];
				}
			}
		
			if(max_val<present[j])
				max_val = present[j];

			// cout<<dp[i][j]<<" ";
		}
		prev = present;
		present.clear();
		present.resize(target+1,0);		
		// cout<<"\n";
	}

	// for(int i = 0;i<dp.size();i++){

	// 	for(int j = 0;j<dp[i].size();j++){

	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }


	// for(int i = 0;i<dp.size();i++){

	// 	for(int j = 0;j<dp[i].size();j++){

	// 		if(max_val<dp[i][j])
	// 			max_val = dp[i][j];
	// 	}
	// }

	diff = sum - 2 * max_val;

}

int main(){

	ios_base::sync_with_stdio(false);

	diff = INT_MAX;

	long long int n, sum = 0;
	cin>>n;

	vector<long long int> arr(n,0);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
		cout<<"SUM: "<<sum<<" "<<i<<"\n";
		sum = (sum + arr[i])%1000000007;
	}

	cout<<"Here\n";

	long long int left = 0,right = 0;

	if(n == 2)
		diff = abs(arr[0] - arr[1]);

	else{
		
		subset_sum(arr,sum/2,sum);
		// dfs(arr,left+arr[0],right,1);
		// dfs(arr,left,right+arr[0],1);
	}

	cout<<diff<<"\n";

	return 0;
}
