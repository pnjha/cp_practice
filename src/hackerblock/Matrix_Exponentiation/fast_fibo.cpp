//https://hack.codingblocks.com/practice/p/349/280

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

vector<vector<ll>> matrix_multiply(vector<vector<ll>>a, vector<vector<ll>> b){

	int n = a.size();

	vector<vector<ll>> c(n,vector<ll>(n,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			c[i][j] = 0;
			for(int k = 0;k<n;k++){
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%MOD)%MOD;
			}
		}
	}
	return c;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>> T,ll n){

	vector<vector<ll>> res(T.size(),vector<ll>(T.size(),0));

	for(int i = 0;i<T.size();i++){
		res[i][i] = 1;
	}

	while(n){

		if(n&1)
			res = matrix_multiply(res, T);

		T = matrix_multiply(T,T);
		n >>= 1;
	}

	return res;
}

ll fast_fib(ll n){

	if(n == 1 || n == 2)
		return 1;

	vector<vector<ll>> T = {{0,1},{1,1}};

	T = matrix_expo(T,n-1);

	return T[1][1];
}

int main(){

	ll t,n;
	cin>>t;

	while(t--){

		cin>>n;

		cout<<fast_fib(n)<<"\n";
	}

	return 0;
}