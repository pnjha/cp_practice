// https://hack.codingblocks.com/practice/p/366/458

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr){

	vector<int> bits(64,0);
	int j = 0;
	
	for(int i = 0;i<arr.size();i++){

		j = 0;

		while(arr[i]){
			if(arr[i]&1)
				bits[j] = (bits[j] + 1)%3;
			j++;
			arr[i] >>= 1;
		}

	}

	int ans = 0;
	for(int i = bits.size()-1;i>=0;i--){
		// cout<<bits[i]<<" ";
		ans <<= 1;
		if(bits[i]==1)
			ans = ans|1;
	}
	// cout<<"\n";
	return ans;
}

int main(){

	int n;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0;i<arr.size();i++)
		cin>>arr[i];

	cout<<solve(arr)<<"\n";

	return 0;
}
