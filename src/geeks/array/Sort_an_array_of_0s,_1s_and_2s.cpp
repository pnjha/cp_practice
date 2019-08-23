#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void dutch_national_flag(vector<ll>& arr){

	int i = 0,j = 0, k = arr.size()-1;

	while(j<=k){
		if(arr[j] == 0){
			swap(arr[i++],arr[j++]);
		}
		else if(arr[j] == 1){
			j++;
		}
		else if(arr[j] == 2){
			swap(arr[j],arr[k--]);
		}
	}
}

int main(){

	int t,n,temp;
	cin>>t;

	vector<ll> arr;

	while(t--){

		cin>>n;

		arr.clear();

		for(int i = 0;i<n;i++){
			cin>>temp;
			arr.push_back(temp);
		}

		dutch_national_flag(arr);

		for(int i = 0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}

	return 0;
}