// https://cses.fi/problemset/task/1632

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool cmp(pair<ll,ll>p1, pair<ll,ll>p2){

	if(p1.second<p2.second)
		return true;
	return false;
}

ll get_movies(ll n,ll k,vector<pair<ll,ll>>& arr){

	sort(arr.begin(),arr.end(),cmp);

	multiset<ll> end_time;

	ll cnt = 0;

	for(int i = 0;i<k;i++){
        end_time.insert(-1);
    }
 
    for(int i = 0;i<arr.size();i++){

        if(arr[i].first >= *end_time.begin()){
            cnt++;
            end_time.erase(--end_time.upper_bound(arr[i].first));
            end_time.insert(arr[i].second);
        }
    }

    return cnt;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,k,a,b;

	cin>>n>>k;

	vector<pair<ll,ll>> arr;

	for(int i = 0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b});
	}

	cout<<get_movies(n,k,arr)<<"\n";

	return 0;
}
