// https://cses.fi/problemset/task/1716

#include<bits/stdc++.h>
#define MOD 1000000007
#define SIZE 10000007
#define ll long long int
using namespace std;

vector<ll> fact_table;

ll factorial(){

	fact_table.clear();
	fact_table.resize(SIZE,0);

	fact_table[0] = 1;
	fact_table[1] = 1;

	for(int i = 2;i<SIZE;i++){
		fact_table[i] = (fact_table[i-1]*i)%MOD;
	}
}

ll modular_expo(ll a,ll b, ll p){

	ll res = 1;

	while(b){

		if(b&1)
			res = (res * a)%p;

		a = (a * a)%p;
		b >>= 1;
	}

	return res;
}

ll inverse(ll n){
	return modular_expo(n,MOD-2,MOD);
}

int main(){

	ll n,r;
	cin>>n>>r;

	factorial();

	swap(n,r);

	//(n-r+1)C(r-1)

	ll ans = (((fact_table[n+r-1])%MOD*(inverse(fact_table[r-1]))%MOD)%MOD*(inverse(fact_table[n])%MOD))%MOD;

	cout<<ans<<"\n";

	return 0;
}