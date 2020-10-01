// https://cses.fi/problemset/task/1145/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void longest_increasing_subsequence(vector<ll>& arr){

	int length = 0,n = arr.size(),left = 1,right = 0,mid = 0;
	vector<ll> lis(n+1,0);

	for(int i = 0;i<n;i++){
		left = 1,right = length,mid = 0;
		while(left<=right){
			mid = left + (right - left)/2;
			if(arr[lis[mid]] < arr[i])
				left = mid+1;
			else
				right = mid-1; 
		}
		lis[left] = i;
		if(left>length)
			length = left;
	}

	cout<<length<<"\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin>>n;

	vector<ll> arr(n,0);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	longest_increasing_subsequence(arr);

	return 0;
}
