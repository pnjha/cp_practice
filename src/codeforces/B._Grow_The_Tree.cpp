// https://codeforces.com/contest/1248/problem/B
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	ll x=0,y=0,l=0,r=n-1;

	while(l<=r){
		// cout<<x<<" "<<y<<"\n";
		if(l!=r){
			y += a[l];
			x += a[r];
		}else{
			x += a[l];
			l++;
		}
		l++,r--;
	}

	cout<<(x*x+y*y)<<"\n";

	return 0;
}