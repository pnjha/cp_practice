// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll largest_zero_sum_subarray(vector<ll>& arr){

	ll cnt = 0,sum = 0;

	unordered_map<ll,ll> mp;

	if(arr[0] == 0)
		cnt = 1;

	for(int i = 0;i<arr.size();i++){

		sum += arr[i];

		//important condition
		if(sum == 0){
		    cnt = i+1;
		    continue;
		}

		if(mp.find(sum)==mp.end()){
			mp[sum] = i;
		}else{
			if((i - mp[sum])>cnt)
				cnt = i - mp[sum];
		}
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

		cout<<largest_zero_sum_subarray(arr)<<"\n";

	}

	return 0;
}
