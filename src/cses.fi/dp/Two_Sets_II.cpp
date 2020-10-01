// https://cses.fi/problemset/task/1093

#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

ll bottomup_solution(ll n){

	ll sum = (n*(n+1))/2;

	vector<ll> dp(125255,0);
	dp[0] = 1;
 
	for(int i = 1;i<=n;i++){
 
		for(int j = sum/2;j>=i;j--){
 
			dp[j] = (dp[j] + dp[j-i])%MOD;
		}
	}
 
	return ((dp[sum/2])*500000004)%MOD;
}

// vector<vector<ll>> memo(501,vector<ll>(100000,-1));

// ll topdown_solution_1(ll n, ll index, ll sum){
	
// 	if(sum*2>(n*(n+1))/2)
// 		return 0;

// 	if(index == n){
// 		if(sum*2 == (n*(n+1))/2){
// 			return 1;
// 		}else{
// 			return 0;
// 		}
// 	}

// 	if(memo[index][sum]!=-1)
// 		return memo[index][sum];

// 	if(sum*2 == (n*(n+1))/2){
// 		return 1;
// 	}

// 	ll cnt = 0;

// 	for(int i = index+1;i<=n;i++){
// 		if((sum+i)*2<=((n*(n+1))/2))
// 			cnt = (cnt + topdown_solution_1(n,i,sum+i))%MOD;
// 	}

// 	memo[index][sum] = cnt;

// 	return cnt;
// }

// ll topdown_solution(ll n, ll index, ll sum){
	
//     if(index==n){
//         return ((2*sum)==(n*(n+1)/2));
//     }

//     if(memo[index][sum]!=-1)
//     	return memo[index][sum];

//     ll cnt=0;
    
//     cnt=(topdown_solution(n,index+1,sum)%MOD+(topdown_solution(n,index+1,sum+index))%MOD)%MOD;
    
//     memo[index][sum] = cnt;

//     return cnt;
// }

int main(){

	// freopen("ouput.txt","w",stdout);

	ll n;
	cin>>n;

	if((n*(n+1))%4!=0){
		cout<<"0\n";
		return 0;
	}

	
	cout<<bottomup_solution(n)<<"\n";
	// memo.clear();
	// memo.resize(501,vector<ll>(100000,-1));
	// cout<<topdown_solution_1(n,1,1)<<"\n";
	// memo.clear();
	// memo.resize(501,vector<ll>(100000,-1));
	// cout<<topdown_solution(n,01,01)%MOD<<"\n";

	return 0;
}
