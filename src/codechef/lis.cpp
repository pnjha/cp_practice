// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
// https://www.codechef.com/problems/PEC005

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void longest_increasing_subsequence(vector<ll>& arr){

    if(arr.size() == 0){
        cout<<"0\n";
        return;
    }

	ll lis_length = 0;
	vector<ll> parent(arr.size(),-1);
	vector<pair<ll,ll>> lis(arr.size()+1);

	for(ll i = 0;i<arr.size();i++){

		ll left = 1, right = lis_length, mid = 0;

		while(left<=right){
	
			mid = left + (right - left)/2;
		
			// '<' for strictly increasing case ans '<=' otherwise
			if(lis[mid].first <= arr[i])
				left = mid+1;
			else
				right = mid-1;
		}

		lis[left] = {arr[i],i};

		if(left>lis_length)
			lis_length = left;
	}
	
	cout<<lis_length<<"\n";
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ll n,t;
	cin>>t;

	vector<ll> arr;
	
	while(t--){
		
		cin>>n;

		arr.clear();
		arr.resize(n,0);

		for(ll i = 0;i<n;i++)
			cin>>arr[i];
		
		longest_increasing_subsequence(arr);
	}

	return 0;
}

