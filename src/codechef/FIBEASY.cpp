// https://www.codechef.com/SEPT19B/problems/FIBEASY
#include<iostream>
#include<vector>
#include<math.h>
#define ll long long int

using namespace std;

vector<vector<ll>> matrix_multiply(vector<vector<ll>>& a,vector<vector<ll>>& b){
	
	int n = a.size();
	vector<vector<ll>> c(n,vector<ll>(n,0));
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			c[i][j] = 0;
			for(int k = 0;k<n;k++){
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]))%10;
			}
		}
	}
	return c;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>>& a,ll n){

	int p = a.size();
	vector<vector<ll>> res(p,vector<ll>(p,0));

	for(int i = 0;i<p;i++){
		res[i][i] = 1;
	}

	while(n){
		if(n&1)
			res = matrix_multiply(res,a);
		a = matrix_multiply(a,a);
		n >>= 1;
	}
	return res;
}

ll fibonacci(ll n){

	if(n == 0)
		return 0;

	if(n == 1 || n == 2)
		return 1;

	vector<vector<ll>> T = {{0,1},{1,1}};

	T = matrix_expo(T,n-1);

	return T[1][1];
}

ll modular_expo(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1){
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

// int fib(ll n, ll&a, ll&b){

// 	ll a,b;

// 	if(n == 0):
// 		return 1;
// 	if(n == 1 || n == 2)
// 		return 1;
// 	else{

// 		a, b = fib(n/2,a,b)
// 		c = a * (b * 2 - a)
// 		d = a * a + b * b
// 		if n % 2 == 0:
// 			return (c, d)
// 		else:
// 			return (d, c + d)
// 	}
// }

int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	// vector<pair<ll,ll>> mapping;

	// for(int i = 0;i<61;i++){
	// 	ll temp = modular_expo(2,i);
	// 	mapping.push_back({temp,fibonacci(temp-1)%10});
	// }

	// freopen("output.txt","w",stdout);

	// for(int i = 0;i<61;i++){
	// 	cout<<"{"<<mapping[i].first<<","<<mapping[i].second<<"},";
	// }



	vector<pair<ll,ll>> mapping = {{0,0},{1,0},{2,1},{4,2},{8,3},{16,0},{32,9},{64,2},{128,3},{256,0},{512,9},{1024,2},{2048,3},
	{4096,0},{8192,9},{16384,2},{32768,3},{65536,0},{131072,9},{262144,2},{524288,3},{1048576,0},{2097152,9},{4194304,2},
	{8388608,3},{16777216,0},{33554432,9},{67108864,2},{134217728,3},{268435456,0},{536870912,9},{1073741824,2},
	{2147483648,3},{4294967296,0},{8589934592,9},{17179869184,2},{34359738368,3},{68719476736,0},{137438953472,9},{274877906944,2}
	,{549755813888,3},{1099511627776,0},{2199023255552,9},{4398046511104,2},{8796093022208,3},{17592186044416,0},{35184372088832,9}
	,{70368744177664,2},{140737488355328,3},{281474976710656,0},{562949953421312,9},{1125899906842624,2},{2251799813685248,3},
	{4503599627370496,0},{9007199254740992,9},{18014398509481984,2},{36028797018963968,3},{72057594037927936,0},
	{144115188075855872,9},{288230376151711744,2},{576460752303423488,3},{1152921504606846976,0}};

	ll t,n,p;
	cin>>t;

	while(t--){

		cin>>n;

		if(n == 1){
			cout<<"0\n";
		}else if(n == 2 || n == 3){
			cout<<"1\n";
		}else{
			int i = 0;
			for(i = 0;i<mapping.size();i++){
				if(n < mapping[i].first)
					break;
			}
			cout<<mapping[i-1].second<<"\n";
		}
	}

	return 0;
}