// https://www.codechef.com/OCT19B/problems/S10E

#include<bits/stdc++.h>

using namespace std;

int count_goodays(int arr[], int n){

	int cnt = 1,min_ele = INT_MAX;

	for(int i = 1;i<n;i++){
		min_ele = INT_MAX;
		// cout<<setw(3)<<i<<"\n";
		for(int j = i-1;j>i-6 && j>=0;j--){
			// cout<<setw(6)<<j<<"\n";
			min_ele = min(min_ele, arr[j]); 
		}
		if(min_ele>arr[i])
			cnt++;
	}

	return cnt;
}

int main(){

	int t,n;
	cin>>t;

	while(t--){

		cin>>n;

		int arr[n];
		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<count_goodays(arr,n)<<"\n";
	}

	return 0;
}
