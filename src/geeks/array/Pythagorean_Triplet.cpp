#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool pythogorean_triplet(unordered_set<ll>& arr){

	vector<ll> a;

	for(auto itr = arr.begin();itr != arr.end(); itr++){
		a.push_back(sqrt(*itr));
	}

	for(int i = 0;i<a.size();i++){
		for(int j = i+1;j<a.size();j++){
			if(arr.find((a[i]*a[i]) + (a[j]*a[j]))!=arr.end())
				return true;
		}
	}

	return false;
}


int main(){

	int t,n,temp;
	cin>>t;

	unordered_set<ll> arr;

	while(t--){

		cin>>n;

		arr.clear();

		for(int i = 0;i<n;i++){
			cin>>temp;
			arr.insert(temp*temp);
		}

		if(pythogorean_triplet(arr)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}

	return 0;
}