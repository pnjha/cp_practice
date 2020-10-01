// https://codeforces.com/contest/1234/problem/A

#include<bits/stdc++.h>
#define  ll long long int

using namespace std;

int main(){

	ll q,n,a,b;

	cin>>q;

	while(q--){

		cin>>n;

		a = 0;

		for(int i = 0;i<n;i++){
			cin>>b;
			a += b;
		}

		cout<<int(ceil((double)(((double)a)/((double)n))))<<"\n";
	}

	return 0;
}
