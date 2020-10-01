 // Friends Pairing Problem
// https://online.codingblocks.com/player/33819/content/13675/5227

#include<bits/stdc++.h>
#define int long long int
using namespace std;

int num_friends_pairs_rec(int n){

	if(n == 1)
		return 1;
	if(n == 2)
		return 2;

	int ans = num_friends_pairs_rec(n-2) * (n-1) + num_friends_pairs_rec(n-1);

	return ans;
}

int num_friends_pairs(int n){

	if(n == 1)
		return 1;
	if(n == 2)
		return 2;

	vector<int> arr(n+1,0);

	arr[1] = 1;
	arr[2] = 2;

	for(int i = 3;i<=n;i++){

		arr[i] = arr[i-2] * (i-1) + arr[i-1];

	}

	return arr.back();
}

int32_t main(){

	int t,n;

	cin>>t;

	while(t--){

		cin>>n;

		cout<<num_friends_pairs(n)<<"\n";
	}

	return 0;
}
