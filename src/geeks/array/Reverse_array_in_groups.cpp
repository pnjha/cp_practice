#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void reverse_group(vector<ll>& arr,int k){

	int i = 0;
	
	while(i<arr.size()){

		if(i+k<arr.size()){
			reverse(arr.begin()+i,arr.begin()+i+k);
			i += k;
		}else{
			reverse(arr.begin()+i,arr.end());
			break;
		}

	}
}

int main(){

	int t,n,temp,k;
	cin>>t;

	vector<ll> arr;

	while(t--){

		cin>>n>>k;

		arr.clear();

		for(int i = 0;i<n;i++){
			cin>>temp;
			arr.push_back(temp);
		}

		reverse_group(arr,k);

		for(int i = 0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}

	return 0;
}