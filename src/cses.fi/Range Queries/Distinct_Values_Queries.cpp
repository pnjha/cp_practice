// https://cses.fi/problemset/task/1734
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	ll n,q,a,b;
	cin>>n>>q;
	vector<ll> arr(n);
	vector<pair<ll,map<ll,bool>>> tree(4*n+1);
	
	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree();

	for(int i = 0;i<q;i++){
		cin>>a>>b;
		a--,b--;
		cout<<query()<<"\n";
	}

	return 0;
}

/*
5 3
3 2 3 1 2
1 3
2 4
1 5
*/