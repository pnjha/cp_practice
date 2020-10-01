// https://codeforces.com/contest/1270/problem/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	//freopen("input.txt","r",stdin);

	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		vector<ll> arr(n);
		ll x=0,y=0;
		for(int i = 0;i<n;i++){
			cin>>arr[i];
			x = x^arr[i];
			y += arr[i];
		}

		if(x*2 == y){
			cout<<"0\n";
			cout<<"\n";
		}else{
			cout<<"2\n";
			cout<<x<<" "<<x+y<<"\n";
		}
	}

	return 0;
}
