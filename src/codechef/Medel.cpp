// https://www.codechef.com/COOK111B/problems/MDL
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

bool cmp(pair<ll,ll>p1, pair<ll,ll>p2){
	if(p1.first<p2.first) return true;
	else if(p1.first == p2.first){
		if(p1.second<p2.second) return true;
	}
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		ll a=-1,b=-1,c=-1,d=-1,i=3;
		cin>>a>>b>>c;
		vector<pair<ll,ll>> arr = {{a,0},{b,1},{c,2}};
		sort(arr.begin(),arr.end(),cmp);
		arr.erase(arr.begin()+1);
		n-=3;
		while(n--){
			cin>>d;
			arr.push_back({d,i});
			sort(arr.begin(),arr.end(),cmp);
			arr.erase(arr.begin()+1);
			i++;
		}
		sort(arr.begin(),arr.end(),cmp);
		if(arr[0].second<arr[1].second){
			a = arr[0].first,b = arr[1].first;
		}else{
 			b = arr[0].first,a = arr[1].first;
		}
		cout<<a<<" "<<b<<"\n";
	}

	return 0;
}
