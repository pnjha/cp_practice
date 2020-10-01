// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd/00000000001a274e
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);
	int t;cin>>t;
	for(int k = 1;k<=t;k++){
		vector<ll> ans;

		ll n,temp,m=LONG_MIN;
		cin>>n;
		vector<ll> dp(n+1,0);

		for(int i = 1;i<=n;i++){
			cin>>temp;
			m=LONG_MIN;
			for(int j = 1;j<=n&&j<=temp;j++){
				dp[j]++;
				if(dp[j]==j) m = j;
			}
			if(ans.size()==0) ans.push_back(1);
			else{
				if(m==LONG_MIN){
					m = ans.back();
				}
				ans.push_back(m);
			}
		}

		cout <<"Case #" << k <<": ";
		for(int i = 0;i<ans.size();i++) if(i!=ans.size()-1) cout<<ans[i]<<" "; else cout<<ans[i];
		cout<<"\n";
	}	
	return 0;
}
