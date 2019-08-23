// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll zero_sim_subarray(vector<ll>& arr){

	ll cnt = 0,sum = 0;

	unordered_map<ll,ll> mp;
	mp.reserve(65536);
	mp.max_load_factor(0.25);

	mp[0] = 1;

	for(int i = 0;i<arr.size();i++){

		sum += arr[i];
		cnt += mp[sum];
		mp[sum]++;
	}

	return cnt;
}

int main(){

	int t,n;
	cin>>t;

	vector<ll> arr;

	while(t--){

		cin>>n;

		arr.clear();
		arr.resize(n,0);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<zero_sim_subarray(arr)<<"\n";

	}

	return 0;
}
