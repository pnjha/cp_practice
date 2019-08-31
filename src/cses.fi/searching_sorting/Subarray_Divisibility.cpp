// https://cses.fi/problemset/task/1662
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll subarray_divisibility(vector<ll>& arr){

	ll ans = 0, n = arr.size(),sum = 0;
	vector<ll> cnt(n,0);

	for(int i = 0;i<n;i++){
		sum += arr[i];
 		cnt[((sum%n)+n)%n]++;
	}

	for(int i = 0;i<n;i++){
		ans += (cnt[i] * (cnt[i] - 1))/2;
	}

	ans += cnt[0];

	return ans;
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin>>n;

	vector<ll> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	cout<<subarray_divisibility(arr)<<"\n";

	return 0;
}
