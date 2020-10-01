#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;

	vector<int> arr(n,0);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	long long int count = 0;

	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1]){
			count += (arr[i-1] - arr[i]);
			arr[i] = arr[i-1];
		}
	}

	cout<<count<<"\n";
	return 0;
}
