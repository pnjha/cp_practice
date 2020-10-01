//https://hack.codingblocks.com/practice/p/349/757

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000000

using namespace std;

vector<vector<ll>> matrix_multiply(vector<vector<ll>> a, vector<vector<ll>> b){

	int n = a.size();

	vector<vector<ll>> c(n,vector<ll>(n,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%MOD)%MOD;
			}
		}
	}

	return c;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>> a, int p){

	int n = a.size();

	vector<vector<ll>> res(n,vector<ll>(n,0));	

	for(int i = 0;i<n;i++)
		res[i][i] = 1;

	while(p){

		if(p&1)
			res = matrix_multiply(res, a);
		
		a = matrix_multiply(a,a);
		p >>= 1;
	}

	return res;
}

ll solve(vector<ll> b, vector<ll> c, ll k, ll n){

	if(n<=k)
		return b[n-1];

	vector<vector<ll>> t(k,vector<ll>(k,0));	

	for(int i = 0;i<k;i++){
		for(int j = 0;j<k;j++){

			if(i+1 == j){
				t[i][j] = 1;
			}
			if(i == k-1)
				t[i][j] = c[k-j-1];
		}
	}

	t = matrix_expo(t,n-1);

	ll ans = 0;

	for(int i = 0;i<k;i++){
		ans = (ans + (t[0][i] * b[i])%MOD)%MOD;
	}

	return ans;
}

int main(){

	ll t,n,k;
	cin>>t;

	vector<ll> b,c;

	while(t--){

		cin>>k;

		b.clear();
		b.resize(k);

		c.clear();
		c.resize(k);

		for(int i = 0;i<k;i++)
			cin>>b[i];
		for(int i = 0;i<k;i++)
			cin>>c[i];

		cin>>n;

		cout<<solve(b,c,k,n)<<"\n";
	}

	return 0;
}
