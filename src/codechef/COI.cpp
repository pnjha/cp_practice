#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> arr;

ll min_cost(ll l, ll r, ll y){

	ll cost = 0;

	vector<ll> temp(arr.begin()+l-1,arr.begin()+r);
		
	// for(int i = 0;i<temp.size();i++)
	// 	cout<<temp[i]<<" ";
	// cout<<"\n";

	sort(temp.begin(),temp.end());

	int i = 0;
	
	while(cost<y && i<temp.size()){
		cost += temp[i];
		i++;
	}

	if(cost < y)
		return -1;

	return cost;
}

int main(){

	ll n,q,l,r,y;
	
	cin>>n;

	arr.clear();
	arr.resize(n,0);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	cin>>q;

	while(q--){

		cin>>l>>r>>y;

		cout<<min_cost(l,r,y)<<"\n";

	}

	return 0;
}