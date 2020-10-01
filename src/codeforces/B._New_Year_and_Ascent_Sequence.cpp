// https://codeforces.com/contest/1284/problem/B
#include<bits/stdc++.h>
#define ll long long int 
#define SIZE 1000007

using namespace std;

struct info{
	ll min_val;
	ll max_val;
	bool flag;
};

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll* hash;
	hash = new ll[SIZE];
	memset(hash,0,sizeof(hash));
	
	ll n,l,ans = 0,p = 0;
	cin>>n;

	ans = n*n;

	vector<vector<ll>> arr(n);
	for(int i = 0;i<n;i++){
		cin>>l;
		arr[i].resize(l);
		for(int j = 0;j<l;j++){
			cin>>arr[i][j];
		}
	}

	vector<info> a;

	for(int i = 0;i<n;i++){
		ll ma = arr[i].back(), mi = arr[i].back(), temp = arr[i].back();
		bool xflag = false;
		for(int j = arr[i].size()-2;j>=0;j--){
			ma = max(ma,arr[i][j]);
			mi = min(mi,arr[i][j]);
			if(!xflag){
				if(arr[i][j]<temp){
					xflag = true;
				}else{
					temp = arr[i][j]; 
				}
			}
		}

		if(!xflag){
			a.push_back({mi,ma,xflag});
			hash[ma]++;
		}
	}

	for(int i = 1;i<SIZE;i++) hash[i] = hash[i-1] + hash[i];

	for(int i = 0;i<a.size();i++){
		
		ans -= hash[a[i].min_val];
	}

	cout<<ans<<"\n";

	return 0;
}

/*
5
1 1
1 1
1 2
1 4
1 3
*/