#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x;
	cin>>n>>x;

	vector<int> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	vector<int> num_coins(x+1,INT_MAX);
	num_coins[0] = 0;

	// sort(arr.begin(),arr.end(),greater<int>());

	for(int i = 0;i<arr.size();i++){

		for(int j = arr[i];j<num_coins.size();j++){

			if(arr[i] > j)
				continue;
			else{
				num_coins[j] = min(num_coins[j],num_coins[j-arr[i]]!=INT_MAX?num_coins[j-arr[i]]+1:INT_MAX);
			}
		}
	}


	if(num_coins.back()==INT_MAX)
		cout<<"-1\n";
	else
		cout<<num_coins.back()<<"\n";

	return 0;
}
