// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fe36

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t,m,n;
	cin>>t;

	for(int k = 1;k<=t;k++){

		ll ans = 0;
		cin>>n>>m;
		ll arr[n];

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		for(int i = 51;i>=0;i--){
			ll cnt = 0;
			for(int j = 0;j<n;j++){
				if(arr[j]&(1LL<<i)) cnt++;
			}
			if(cnt>(n-cnt)) ans = ans | (1LL<<i);
		}

		ll temp = 0;
		for(int j = 0;j<n;j++){
			temp += (arr[j] ^ ans);
		}

		// cout<<temp<<"\n";

		if(temp<=m){			
			for(int i = 51;i>=0;i--){
				if(!(ans&(1LL<<i))){
					
					ll kk = ans | (1LL<<i);
					temp=0;
					for(int j = 0;j<n;j++){
						temp += (arr[j] ^ kk);
					}
					if(temp<=m) ans = max(ans,kk);
					// cout<<"kk: "<<kk<<" "<<"temp: "<<temp<<" "<<ans<<"\n";
				}
			}
		}else{
			ans = -1;
		}

		cout <<"Case #" << k <<": "<<ans<<"\n";
	}

	return 0;
}