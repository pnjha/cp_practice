#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

vector<ll> arr;
vector<vector<ll>> dp;

ll dfs(int index,int k, int p){

	if(index >= arr.size())
		return 0;
	
	if(k == 0){
		return 1;
	}

	ll n = arr.size(),ans = 0;

	for(int i = index+1;i<n-k+1;i++){

		if((arr[i] - arr[index]) <= p){

			if(dp[i][k-1]==-1){
				if(k-1>0)
					dp[i][k-1] = dfs(i,k-1,p);
				else if(k-1==0)
					dp[i][k-1] = 1;
				else
					dp[i][k-1] = 0;
			}
				
			ans = (ans + dp[i][k-1])%MOD;
		}
		else
			break;
	}

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t,n,k,p,ans = 0;

	cin>>t;

	while(t--){

		cin>>n>>k>>p;
		
		arr.clear();
		arr.resize(n,0);

		dp.clear();
		dp.resize(n,vector<ll>(k,-1));

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr.begin(),arr.end());
		ans = 0;

		for(int i = 0;i<n-k+1;i++){
			for(int j = i+1;j<n-k+2;j++){
				if(arr[j]-arr[i]<=p){
					if(k-2>=0){
						if(dp[j][k-2]==-1){
							if(k-2>0){
								dp[j][k-2] = dfs(j,k-2,p);
							}else if(k-2 == 0){
								dp[j][k-2] = 1;
							}
						}
						ans = (ans + dp[j][k-2])%MOD;
					}else{
						break;
					}
				}else{
					break;
				}
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}