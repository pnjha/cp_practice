// https://www.spoj.com/problems/SEQ/

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000000
using namespace std;

vector<ll> b,c;

void print_matrix(vector<vector<ll>> a){
	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<a.size();j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n";
	}cout<<"\n";
}

vector<vector<ll>> matrix_multiply(vector<vector<ll>> a, vector<vector<ll>> b){

	vector<vector<ll>> ans(a.size(),vector<ll>(a.size(),0));

	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			ans[i][j] = 0;
			for(int k = 0;k<a.size();k++){
				ans[i][j] = (ans[i][j]%MOD + (a[i][k]%MOD * b[k][j]%MOD)%MOD)%MOD;
			}
		}
	}

	return ans;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>> A, int p){

    // if(p==1){
    //     return A;
    // }
     
    // if(p&1){
    //     return matrix_multiply(A, matrix_expo(A,p-1));
    // }
    // else{
        
    //     vector<vector<ll> > X = matrix_expo(A,p/2);
    //     return matrix_multiply(X,X);
     
    // }

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

ll get_seq_num(int n){

	int k = b.size();

	if(n < k)
		return b[n-1];

	vector<vector<ll>> T(k,vector<ll>(k,0));

	for(int i = 0;i<T.size();i++){
		for(int j = 0;j<T.size();j++){

			if(i == T.size()-1){
				T[i][j] = c[k-j-1];
			}else if(i + 1 == j){
				T[i][j] = 1;
			}
		}
	}

	// print_matrix(T);

	ll ans = 0;

	T = matrix_expo(T,n-1);

	// print_matrix(T);

	for(int j = 0;j<T.size();j++){
		ans = (ans + (T[0][j] * b[j])%MOD)%MOD; 
	}

	return ans;
}

int main(){

	int t,k,n;
	cin>>t;

	while(t--){

		cin>>k;
		b.clear();
		c.clear();

		b.resize(k);
		c.resize(k);

		for(int i = 0;i<k;i++)
			cin>>b[i];
		
		for(int i = 0;i<k;i++)
			cin>>c[i];
		
		cin>>n;

		cout<<get_seq_num(n)<<"\n";
	}

}


// #define lop(i, a, b)    for (int i = a; i < b; i++)

// const int M = 5;
// struct mat_expo
// {
//      int m[M][M];

//      mat_expo() { memset(m, 0, sizeof m); }

//      void eye() { lop(i, 0, M) m[i][i] = 1; }

//      mat_expo operator*(const mat_expo &a) const
//      {
//           mat_expo r;
//           lop(i, 0, M) lop(j, 0, M) lop(k, 0, M)
//                        r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
//           return r;
//      }
// };
// mat_expo getans(mat_expo bb, int k)
// {
//      mat_expo aa;
//      aa.eye();
//      while (k > 0)
//      {
//           if (k & 1) aa = aa * bb;
//           bb = bb * bb;
//           k /= 2;
//      }
//      return aa;
// }