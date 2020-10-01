// https://cses.fi/problemset/task/1164

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool cmp(pair<ll,ll>p1, pair<ll,ll>p2){

	if(p1.second<p2.second)
		return true;
	return false;
}

ll get_movies(ll n,vector<pair<ll,ll>>& arr,vector<ll>& ans){

	sort(arr.begin(),arr.end(),cmp);
	ans.clear();

	ll k = 1;
	multiset<pair<ll,ll>> end_time;

	end_time.insert({-1,k});
	k++;
 
    for(int i = 0;i<arr.size();i++){

        if(arr[i].first >= (*end_time.begin()).first){
        
            end_time.erase(--end_time.upper_bound({arr[i].first,0}));
            end_time.insert({arr[i].second,0});
            
        }else{
			
			end_time.insert({-1,k});
			i--;
			k++;
        }
    }

    return end_time.size();
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,k,a,b;

	cin>>n;

	vector<ll> ans;
	vector<pair<ll,ll>> arr;

	for(int i = 0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b});
	}

	cout<<get_movies(n,arr,ans)<<"\n";

	for(int i = 0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<"\n";

	return 0;
}
