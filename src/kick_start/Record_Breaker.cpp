// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
#include<bits/stdc++.h>
#define  ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t;
	cin>>t;

	for(int k = 1;k<=t;k++){

		ll n, ans = 0, max_val = INT_MIN;
		cin>>n;

		vector<ll> arr(n);

		for(int i = 0;i<n;i++) cin>>arr[i];

		if(n == 1) ans = 1;
		else{
			if(arr[0]>arr[1]) ans = 1;
			max_val = arr[0];

			for(int i = 1;i<n-1;i++){
				if(arr[i]>max_val){
					max_val = arr[i];
					if(arr[i]>arr[i+1]) ans++;
				}
			}

			if(arr.back()>max_val) ans++;
		}

		cout <<"Case #" << k <<": "<<ans<<"\n";
	}

	return 0;
}


/*

4
8
1 2 0 7 2 0 2 0
6
4 8 15 16 23 42
9
3 1 4 1 5 9 2 6 5
6
9 9 9 9 9 9
*/