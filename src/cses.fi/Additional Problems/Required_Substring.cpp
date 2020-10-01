// https://cses.fi/problemset/task/1112

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll factorial(ll n){

	if(n<=1)
		return 1;

	ll res = 1;

	while(n>1){

		res = (res * n)%MOD;
		n -= 1;
	}

	return res%MOD;
}

ll modular_expo(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1)
			res = (res * a)%MOD;
		a = (a * a)%MOD;
		b >>= 1;
	}
	return res%MOD;
}

int main(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	cout<<((factorial((n-s.length()+1))*(modular_expo(26,(n-s.length()))))%MOD)<<"\n";

	return 0;
}