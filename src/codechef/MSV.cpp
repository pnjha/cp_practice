// https://www.codechef.com/OCT19B/problems/MSV

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<ll>> divisors;

void generate_all_divisors(ll n){

	int k = 0;

	divisors.clear();
	divisors.resize(n);

	for(int i = 1;i<n;i++){
		for(int j = i;j<n;j+=i){
			divisors[j].push_back(i);
		}
	}
	
	// for(int i = 1;i<n;i++){
	// 	cout<<i<<" : ";
	// 	for(int j = 0;j<divisors[i].size();j++){
	// 		cout<<divisors[i][j]<<" ";
	// 	}cout<<"\n";
	// }
}

void find_all_divisors(ll n, vector<ll>& d){

	for(int i = 1;i*i<=n;i++){
		if(n%i==0){
			d.push_back(i);
			if(n/i!=i)
				d.push_back(n/i);
		}
	}

	// for(int i = 0;i<d.size();i++)
	// 	cout<<d[i]<<" ";
	// cout<<"\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t,n;
	cin>>t;

	while(t--){

		cin>>n;

		// vector<ll> arr(n),d;

		ll arr[n];

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		map<ll,ll> mp;
		ll max_val = 0;

		for(int i = 1;i<n;i++){
			
			// d.clear();
			int d[300],l=0;
			
			for(int j = 1;j*j<=arr[i-1];j++){
				if(arr[i-1]%j==0){
					d[l] = j;
					l++;
					if(arr[i-1]/j!=j){
						d[l] = arr[i-1]/j;
						l++;
					}
				}
			}

			// find_all_divisors(arr[i-1],d);
			for(int j = 0;j<l;j++){
				mp[d[j]]++;
			}
			max_val = max(max_val, mp[arr[i]]);

			for(auto x:mp){
				cout<<x.first<<" : "<<x.second<<" ";
			}cout<<"\n";
		}

		cout<<max_val<<"\n";
	}

	return 0;
}