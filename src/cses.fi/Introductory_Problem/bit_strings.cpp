#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int modular_exponentiation(long long int base,long long int power){

	if(base == 1 || base == 0 || power == 1)
		return base%MOD;

	if(power == 0)
		return 1;

	long long int ans = modular_exponentiation(base,power/2)%MOD;

	if(power%2 == 1){

		ans = (ans*(ans*base)%MOD)%MOD;

	}else{

		ans = (ans*ans)%MOD;
	}

	return ans;	
}

int main(){

	ios_base::sync_with_stdio(NULL);

	long long int n;
	cin>>n;

	cout<<modular_exponentiation(2,n)<<"\n";

	return 0;
}
