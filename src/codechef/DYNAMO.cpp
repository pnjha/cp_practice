// https://www.codechef.com/JAN20B/problems/DYNAMO
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

ll expo(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
          
		ll n,a,s,b,c,d,e,p;
		cin>>n;
		cin>>a;
		p = expo(10,n)-1;
		//cout<<expo(10,n)<<"\n";
		s = a + 2*p+2;
		cout<<s<<"\n";
		cout.flush();
		s -= a;
		cin>>b;
		s -= b;
		// if(b == 1) cout<<
		c = p-b+1;//(p-b)>0?(p-b):1;
		cout<<c<<"\n";
		cout.flush();
		s -= c;
		cin>>d;
		cout<<(s - d)<<"\n";
		cout.flush();
		cin>>p;
		if(p == -1) return 0;
	}


	return 0;
}
