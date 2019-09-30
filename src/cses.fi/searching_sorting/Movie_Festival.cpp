// https://cses.fi/problemset/task/1629

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool cmp(pair<ll,ll>p1,pair<ll,ll>p2){

	if(p1.second<p2.second)
		return true;
	return false;
}

ll get_max_movies(vector<pair<ll,ll>>& arr){

	sort(arr.begin(),arr.end(),cmp);

	ll cnt = 1;
	ll last_end = arr[0].second;

	for(int i = 1;i<arr.size();i++){

		if(arr[i].first>=last_end){

			cnt++;
			last_end = arr[i].second;
		}
	}

	return cnt;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,a,b;

	cin>>n;

	vector<pair<ll,ll>> arr;
	
	for(int i = 0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b});
	}

	cout<<get_max_movies(arr)<<"\n";

	return 0;
}



