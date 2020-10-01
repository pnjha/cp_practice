// https://codeforces.com/contest/1238/problem/B
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t,n,r,a;
	cin>>t;

	while(t--){

		cin>>n>>r;

		vector<ll> arr;
		set<ll> s;

		for(int i = 0;i<n;i++){
			cin>>a;
			s.insert(a);
		}

		arr = {s.begin(),s.end()};
		
		n = arr.size();

		ll buckets = int(ceil(arr[n-1]/r)),cnt = 0;
		ll ans = 0;
		// cout<<buckets<<"\n";

		for(int i = n-1;i>=0;i--){
			// cout<<cnt*r<<" "<<arr[i]<<"\n";
			if(cnt*r<arr[i]){
				ans++;
				cnt++;
			}else{
				break;
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}
