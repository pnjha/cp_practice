// https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll n,s = 0,a,b;
	cin>>n;

	while(n){

		a = n;
		b = LONG_MIN;

		while(a){
			b = max(b,a%10);
			a = a/10;
		}

		n = n - b;
		s++;
	}

	cout<<s<<"\n";

	return 0;
}
