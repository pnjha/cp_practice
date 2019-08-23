#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll trapped_water(vector<ll>& arr){

	ll ans = 0,msf = -1;
	vector<ll> left(arr.size(),0);
	vector<ll> right(arr.size(),0);

	left[0] = arr[0];
	right[right.size()-1] = arr.back();

	msf = arr[0];

	for(int i = 1;i<arr.size();i++){
		if(arr[i] > msf){
			msf = arr[i];
		}
		left[i] = msf;
	}

	for(int i = 0;i<left.size();i++)
		cout<<left[i]<<" ";
	cout<<"\n";

	msf = arr.back();

	for(int i = arr.size() - 2;i>=0;i--){
		if(arr[i] > msf){
			msf = arr[i];
		}
		right[i] = msf;
	}

	for(int i = 0;i<left.size();i++)
		cout<<right[i]<<" ";
	cout<<"\n";

	ans = 0;

	for(int i = 0;i<arr.size();i++){
		ans = ans + min(left[i], right[i]) - arr[i];
	}

	return ans;
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

		cout<<trapped_water(arr)<<"\n";

	}

	return 0;
}
