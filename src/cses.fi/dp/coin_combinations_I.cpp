#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;


int main(){

	// ios_base::sync_with_stdio(NULL);
	// cin.tie(NULL);
	// cout.tie(NULL);

	// freopen("input.txt","r",stdin);

	ll n,x,a;
	cin>>n>>x;

	vector<ll> coins(n);

	for(int i = 0;i<n;i++)
		cin>>coins[i];

	vector<ll> dp(x+1,0);

	dp[0] = 1;

	for(int i = 1;i<=x;i++){
		for(int j = 0;j<n;j++){
			if(i-coins[j]>=0){
				dp[i] = (dp[i] + dp[i-coins[j]])%MOD;
			}
		}
	}

	cout<<dp[x]<<"\n";

	return 0;
}


// #include<bits/stdc++.h>

// using namespace std;

// unordered_map<int,int> memo;

// int dfs(vector<int>&arr, int index, int sum){

// 	if(memo.find(sum) != memo.end())
// 		return memo[sum];

// 	if(sum == 0){
// 		return 1;
// 	}

// 	if(sum<0)
// 		return 0;

// 	int cnt = 0;

// 	for(int i = 0;i<arr.size();i++){

// 		cnt += dfs(arr,i,sum-arr[i]);
// 	}	

// 	memo[sum] = cnt;
// }

// int main(){

// 	freopen("input.txt","r",stdin);

// 	ios_base::sync_with_stdio(NULL);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	memo.clear();

// 	int n,x;
// 	cin>>n>>x;

// 	vector<int> arr(n);

// 	for(int i = 0;i<n;i++)
// 		cin>>arr[i];

// 	int cnt = 0;

// 	for(int i = 0;i<arr.size();i++){

// 		// if(memo.find(arr[i]) == memo.end()){

// 			cnt += dfs(arr,i,x-arr[i]);
// 			// cnt += memo[arr[i]];

// 		// }else{

// 		// 	cnt += memo[arr[i]];

// 		// }
// 	}

// 	cout<<cnt<<"\n";

// 	return 0;
// }