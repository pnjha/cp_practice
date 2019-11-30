#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i];


	sort(arr.begin(),arr.end());

	int target = 0;

	if(arr.size()&1){
		target = arr[arr.size()/2];
	}else{
		target = (arr[arr.size()/2] + arr[arr.size()/2-1])/2;
	}

	long long int ans = 0;

	for(int i = 0;i<arr.size();i++)
		ans += abs(arr[i] - target);

	cout<<ans<<"\n";

	return 0;
}
