// https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool cmp(pair<ll,int>p1, pair<ll,int>p2){

	if(p1.first<p2.first){
		return true;
	}else if(p1.first == p2.first){
		if(p1.second<p2.second){
			return true;
		}
	}
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,a,b;
	cin>>n;

	vector<pair<ll,int>> arr;

	for(int i = 0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,1});
		arr.push_back({b+1,-1});
	}

	sort(arr.begin(),arr.end(),cmp);

	ll ans=LONG_MIN,temp=0;

	for(int i = 0;i<arr.size();i++){
		temp += arr[i].second;
		if(temp>ans){
			ans = temp;
		}
	}

	cout<<ans<<"\n";

	return 0;
}



















