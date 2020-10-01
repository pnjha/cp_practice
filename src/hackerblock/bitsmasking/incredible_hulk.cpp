// https://hack.codingblocks.com/practice/p/366/135

#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,n,cnt=0;
	cin>>t;

	while(t--){

		cin>>n;
		cnt=0;

		while(n){
			if(n&1){
				cnt++;
			}
			n >>= 1;
		}
		cout<<cnt<<"\n";
	}

	return 0;
}
