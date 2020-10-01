// http://m1.codeforces.com/contest/1279/submit
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	ll t,a,b,c;
	cin>>t;

	while(t--){

		cin>>a>>b>>c;
		if(a+b>=c-1 && a+c>=b-1 && c+b>=a-1) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}
