// https://codeforces.com/contest/1241/problem/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll q,n;

	cin>>q;

	while(q--){

		cin>>n;

		if(n == 2){
			cout<<"2\n";
		}else{
			if(n&1)
				cout<<"1\n";
			else
				cout<<"0\n";
		}
	}

	return 0;
}
