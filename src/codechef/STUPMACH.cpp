// https://www.codechef.com/LTIME79A/problems/STUPMACH
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		ll ans = 0, msf = LONG_MAX, temp;

		for(int i = 0;i<n;i++){
			cin>>temp;
			msf = min(temp,msf);
			ans += msf;
		}

		cout<<ans<<"\n";
	}

	return 0;
}