// https://cses.fi/problemset/task/1661

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll num_subarrays(vector<ll>& arr,int x){

	ll cnt = 0,sum = 0;

	unordered_map<ll,ll> mp;

	mp[0] = 1;

	for(int i = 0;i<arr.size();i++){

		sum += arr[i];
		if(mp.find(sum-x)!=mp.end()){
			// cout<<i<<" "<<sum<<"\n";
			cnt += mp[sum-x];
		}
		mp[sum]++;
	}

	return cnt;
}


int main(){

	int n,x;

	vector<ll> arr;
	cin>>n>>x;

	arr.clear();
	arr.resize(n,0);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	cout<<num_subarrays(arr,x)<<"\n";

	return 0;
}
