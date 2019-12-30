// http://m1.codeforces.com/contest/1270/problem/A
#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,n,k1,k2;
	cin>>t;

	while(t--){

		cin>>n>>k1>>k2;
		int p1 = INT_MIN, p2 = INT_MIN;
		for(int i = 0;i<k1;i++){
			cin>>n;
			p1 = max(n,p1);
		}
		for(int i = 0;i<k2;i++){
			cin>>n;
			p2 = max(n,p2);
		}
		if(p1>p2) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
