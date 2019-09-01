// https://cses.fi/problemset/task/1722

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

vector<vector<ll>> matrix_multiply(vector<vector<ll>>& a, vector<vector<ll>>& b){

	int n = a.size();
	vector<vector<ll>>c(n,vector<ll>(n,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%MOD)%MOD;
			}
		}
	}

	return c;
}

vector<vector<ll>> matrix_expoentiation(vector<vector<ll>>& a, ll p){

	int n = a.size();
	vector<vector<ll>> res(n,vector<ll>(n,0));

	for(int i = 0;i<n;i++)
		res[i][i] = 1;

	while(p){

		if(p&1)
			res = matrix_multiply(res,a);
		a = matrix_multiply(a,a);
		p >>= 1;
	}

	return res;
}

ll fibonacci(ll n){

	if(n == 0)
		return 0;

	if(n == 1 || n == 2)
		return 1;

	vector<vector<ll>> T = {{0,1},{1,1}};

	T = matrix_expoentiation(T,n-1);

	return T[1][1];
}

int main(){

	ll n;
	cin>>n;

	cout<<fibonacci(n)<<"\n";

	return 0;
}
