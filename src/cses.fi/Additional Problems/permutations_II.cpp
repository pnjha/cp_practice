#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int binomial_coefficient(int n, int r){

	if(r > n-r)
		r = n - r;

	long long int ans = 1;	

	for(int i = 0;i<r;i++){

		ans = (ans%MOD * (n-i)%MOD)%MOD;
		ans /= (i+1);
	}

	return ans%MOD;
}

long long int catalan_number(int n){

	if(n == 1|| n == 0)
		return 1;

	long long int ans = 0;
	ans = (binomial_coefficient(2*n,n)%MOD)/(n+1);
	return ans;
}


int main(){
	
	int n;
	cin>>n;

	cout<<catalan_number(n-1)<<"\n";

	return 0;
}
