#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

vector<ll> dp;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin>>n;

	dp.clear();
	dp.resize(n+1,0);

	dp[0] = 1;

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=6;j++){
			if(i-j>=0){
				dp[i] = (dp[i] + dp[i-j])%MOD;
			}
		}
	}

	cout<<dp[n]<<"\n";

	return 0;
}


// struct hash_pair { 
//     template <class T1, class T2> 
//     size_t operator()(const pair<T1, T2>& p) const
//     { 
//         auto hash1 = hash<T1>{}(p.first); 
//         auto hash2 = hash<T2>{}(p.second); 
//         return hash1 ^ hash2; 
//     } 
// }; 

// unordered_map<pair<int,int>,int,hash_pair> dp;

// int dfs(int n,int num){

// 	if(n == 0)
// 		return 1;

// 	if(n<0)
// 		return 0;

// 	if(dp.find({n,num})!=dp.end())
// 		return dp[{n,num}]%MOD;

// 	int cnt = 0;

// 	for(int i = 1;i<=6;i++){
// 		if(n-i>0){

// 			if(dp.find({n-i,i})!=dp.end())
// 				cnt = (cnt + dp[{n-i,i}])%MOD;			
// 			else
// 				cnt = (cnt + dfs(n-i,i))%MOD;
// 		}
// 		if(n-i==0)
// 			cnt = (cnt+1)%MOD;
// 	}

// 	dp[{n,num}] = cnt%MOD;

// 	return dp[{n,num}];	
// }

// int main(){

// 	ios_base::sync_with_stdio(NULL);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int n;
// 	cin>>n;

// 	dp.clear();

// 	int cnt = 0;

// 	for(int i = 1;i<=6;i++)
// 		cnt = (cnt + dfs(n-i,i))%MOD;

// 	cout<<cnt%MOD<<"\n";

// 	return 0;
// }


