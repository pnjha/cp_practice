#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll knapsack(vector<pair<ll,ll>> arr,int m){

	int n = arr.size();
	vector<ll> present(m+1,0);
	vector<ll> prev(m+1,0);

	for(int i = 1;i<n+1;i++){

		present.resize(m+1,0);

		for(int j = 1;j<m+1;j++){

			if(j - arr[i-1].first >= 0){

				present[j] = max(arr[i-1].second + prev[j - arr[i-1].first] , prev[j]);

			}else{

				present[j] = prev[j];
			}

		}
		prev = present;
		present.clear();
	}

	return prev.back();
}	

int main(){

	int n,m;
	cin>>n>>m;

	//weight, cost pair
	vector<pair<ll,ll>> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i].first>>arr[i].second;

	cout<<knapsack(arr,m)<<"\n";

	return 0;
}
