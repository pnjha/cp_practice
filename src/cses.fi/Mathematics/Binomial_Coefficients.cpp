// https://cses.fi/problemset/task/1079

#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;

ll factorial(ll n){
	ll ans = 1;
	while(n>1){
		ans = (ans * n)%MOD;
		n--;
	}
	return ans%MOD;
}

ll modular_expo(ll a, ll b){
	ll res = 1;
	a = a%MOD;
	while(b){
		if(a&1)
			res = (res * a)%MOD;
		a = (a * a)%MOD;
		b >>= 1;
	}
	return res;
}

ll binomial_coeff(ll a,ll b){

	if(b==0)
		return 1;

	ll x = factorial(a)%MOD;
	ll y = modular_expo(factorial(b),MOD-2);
	ll z = modular_expo(factorial(a-b),MOD-2);
	
	return (((x*y)%MOD)*z)%MOD;
}

int main(){

	ll n,a,b;

	cin>>n;

	while(n--){

		cin>>a>>b;

		cout<<(binomial_coeff(a,b)%MOD)<<"\n";
	}

	return 0;
}


		