// https://cses.fi/problemset/task/1098

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll t,n,a = 0,b = 0,v;
	cin>>t;

	while(t--){

		cin>>n;

		a = 0;

		for(int i = 0;i<n;i++){
			cin>>v;
			if(v%4==1)
				a++;
		}

		if(a%2==1) cout<<"first\n";		
		else cout<<"second\n";
	}

}
