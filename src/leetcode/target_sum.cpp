#include<bits/stdc++.h>

using namespace std;

//backtracking approach
// vector<vector<int>> memo;

// int dfs(vector<int>& nums,int x,int index,int S){

//     if(x == S && index == nums.size()){
//         return 1;
//     }        
    
//     if(index>=nums.size())
//         return 0;

//     if(memo[x+1000][index]!=INT_MIN)
// 		return memo[x+1000][index];
    
//     int t,cnt = 0;

//     t = x + nums[index];
//     cnt += dfs(nums,t,index+1,S);

//     t = x - nums[index];
//     cnt += dfs(nums,t,index+1,S);
    
//     cout<<x<<" "<<index<<"\n";
//     memo[x+1000][index] = cnt;

//     return cnt;
// }
// int findTargetSumWays(vector<int>& nums, int S) {
    
// 	int cnt = 0;

// 	memo.clear();    
//   	memo.resize(100007,vector<int>(22,INT_MIN));

//     cnt = dfs(nums,0,0,S);
    
//     return cnt;
// }

//dp approach
//https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation

int subset_sum(vector<int>& nums,int target){

	vector<int>dp(target+1,0);

	dp[0] = 1;

	for(int i = 0;i<nums.size();i++){

		for(int j = target;j>=nums[i];j--){

			dp[j] += dp[j-nums[i]];

		}

	}

	return dp[target];
}

int findTargetSumWays(vector<int>& nums, int S) {
    
	int sum = accumulate(nums.begin(),nums.end(),0);
    
    int cnt = 0,target;

	if(sum<S||(sum+S)&1){
		return cnt;
	}

    target = (sum+S)/2;
	cnt = subset_sum(nums,target);

    return cnt;
}

int main(){

	ios_base::sync_with_stdio(false);

	vector<int> nums = {5,1,2,4,1,1};
	int S = 6;

	cout<<findTargetSumWays(nums,S)<<"\n";

	return 0;
}
