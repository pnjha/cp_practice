// https://cses.fi/problemset/task/1095

#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int expo_recursive(int a, int b){

	if(a == 0 && b == 0)
		return 1;

	if(a == 1 || a == 0 || b == 1)
		return a;
	if(b == 0)
		return 1;

	long long int ans = 0;

	// ans = expo_recursive(a,b/2);

	if(b%2==1){
		ans = a%MOD;
		ans = (ans * expo_recursive(a,b-1)%MOD)%MOD;
	}else{
		ans = expo_recursive(a,b/2)%MOD;
		ans = ((ans)*(ans))%MOD;
	}
	return (ans)%MOD;
}

int expo_iterative(long long int a,int b){

	if(a == 0 && b == 0)
		return 1;

	if(a == 1 || a == 0 || b == 1)
		return a;
	if(b == 0)
		return 1;

	long long int ans = 1; 

	a = a%MOD;

	while(b>0){

		if(b&1){
			ans = (a * ans)%MOD;
		}

		b = b>>1;
		a = (a * a)%MOD;
	}

	return (ans);
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,a,b;
	cin>>t;

	while(t--){

		cin>>a>>b;
		cout<<expo_iterative(a,b)<<" \n";
		// cout<<expo_recursive(a,b)<<" \n";

	}

	return 0;
}
