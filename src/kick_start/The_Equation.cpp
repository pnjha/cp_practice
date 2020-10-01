// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fe36

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll get_msb(ll n){
	ll a = 0,i = 0;
	while(n){
		if(n&1) a = i;
		i++;
		n >>= 1;
	}
	return a+1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);


	ll t,m,n;
	cin>>t;

	for(int k = 1;k<=t;k++){

		ll ans = -1;

		cin>>n>>m;

		ll max_index = 0;
		int arr[n];

		for(int i = 0;i<n;i++){
			cin>>arr[i];
			max_index = max(max_index,get_msb(arr[i]));
		}

		max_index = max(max_index,get_msb(m));

		ll max_range = 1<<(max_index+1);

		for(int i = max_range;i>=0;i--){
			ll temp = 0;
			for(int j = 0;j<n;j++){
				temp += arr[j]^i;
				if(temp>m) break;
			}
			if(temp<=m){
				ans = i;
				break;
			}
		}

		cout <<"Case #" << k <<": "<<ans<<"\n";
	}

	return 0;
}