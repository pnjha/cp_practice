// https://cses.fi/problemset/task/1642
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void print_arr(vector<ll> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void four_sum(vector<ll> arr,ll x){

	if(arr.size()<4){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	ll sum = 0;

	for(int i = 0;i<arr.size();i++){
		sum += arr[i];
	}

	if(arr.size() == 4 && sum == x){
		print_arr(arr);
		return;
	}

	if(sum <= x){
		cout<<"IMPOSSIBLE\n"; 
		return;
	}

	bool flag = false;
	unordered_map<ll,vector<pair<int,int>>> ump;
	vector<ll> ans;
	vector<pair<int,int>>temp;

	for(int i = 0;i<arr.size();i++){
		for(int j = i+1;j<arr.size();j++){
			ump[arr[i] + arr[j]].push_back({i,j});
		}
	}

	for(int i = 0;i<arr.size();i++){
		for(int j = i+1;j<arr.size();j++){
			if(ump.find(x - (arr[i] + arr[j]))!=ump.end()){
				temp = ump[x - (arr[i] + arr[j])];
				for(int k = 0;k<temp.size();k++){
					if(i!=temp[k].first && i!=temp[k].second && j!=temp[k].first && j!=temp[k].second){
						print_arr({i+1,j+1,temp[k].first+1,temp[k].second+1});
						return;
					}
				}
			}
		}
	}	


	if(!flag){
		cout<<"IMPOSSIBLE\n";
		return;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,x;
	cin>>n>>x;

	vector<ll> arr(n,0);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	four_sum(arr,x);

	return 0;
}
