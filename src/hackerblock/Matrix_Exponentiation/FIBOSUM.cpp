//https://hack.codingblocks.com/practice/p/349/758

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll a = 0,n = 0,m = 0;

void print_matrix(vector<vector<ll>> a){
	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<a.size();j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n";
	}cout<<"\n";
}

vector<vector<ll>> matrix_multiply(vector<vector<ll>> A, vector<vector<ll>> B){

	vector<vector<ll>> C(A.size(),vector<ll>(A.size(),0));

	for(int i = 0;i<A.size();i++){
		for(int j = 0;j<B.size();j++){
			C[i][j] = 0;
			for(int k = 0;k<C.size();k++){
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;
			}
		}
	}
	return C;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>> A, int p){

	vector<vector<ll>> res(A.size(),vector<ll>(A.size(),0));	

	for(int i = 0;i<A.size();i++){
		res[i][i] = 1;
	}

	while(p){

		if(p&1)
			res = matrix_multiply(res, A);

		A = matrix_multiply(A, A);
		p >>= 1;
	}

	return res;
}

ll fibsum(ll n){

	if(n == 0)
		return 0;

	if(n == 1 || n == 2)
		return 1;

	vector<vector<ll>> T(2,vector<ll>(2,0));

	T = {{0,1},{1,1}};

	T = matrix_expo(T,n-1);

	// print_matrix(T);

	return (T[1][1])%MOD;
}

int main(){

	ll t;
	cin>>t;

	while(t--){

		cin>>n>>m;
		a = 0;
		a = (fibsum(m+2) - fibsum(n+1) + MOD)%MOD;

		cout<<a<<"\n";
	}

	return 0;
}
