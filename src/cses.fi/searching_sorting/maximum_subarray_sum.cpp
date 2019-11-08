// https://cses.fi/problemset/task/1643
#include<bits/stdc++.h>

using namespace std;

long long int kadane(vector<long long int>& arr){

	long long int msf = INT_MIN, max = 0;
	bool is_positive = false;

	for(int i = 0;i<arr.size();i++){

		if(arr[i]>0)
			is_positive = true;

		max += arr[i];

		if(max<0)
			max = 0;

		if(max>msf)
			msf = max;

	}

	if(!is_positive)
		return -1;

	return msf;
}

int main(){

	int n;
	cin>>n;

	vector<long long int> arr(n);

	for(int i = 0;i<arr.size();i++)
		cin>>arr[i];

	cout<<kadane(arr)<<"\n";

	return 0;
}
