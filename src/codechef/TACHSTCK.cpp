#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,d;
	cin>>n>>d;

	vector<int> arr(n);

	for(int i = 0;i<arr.size();i++)
		cin>>arr[i];

	sort(arr.begin(),arr.end());

	int cnt = 0;

	for(int i = 0;i<n-1;i++){
		if(abs(arr[i]-arr[i+1])<=d){
			cnt++;
			i++;
		}
	}

	cout<<cnt<<"\n";

	return 0;
}
