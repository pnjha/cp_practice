// https://www.codechef.com/AM19MOS/problems/USANBOLT
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ll t;
	double a=0.0,b=0.0,c=0.0,d=0.0;
	cin>>t;

	while(t--){
		cin>>a>>b>>c>>d;
		double tigertime = 0.0, bolttime = 0.0;
		bolttime = a/d;
		tigertime = sqrt((2*(a+b))/c);
		// cout<<bolttime<<" "<<tigertime<<"\n";
		if(bolttime < tigertime) cout<<"Bolt\n";
		else cout<<"Tiger\n";
	}

	return 0;
}

/*
2
10 100 10 10
100 10 5 10
finish distance from bolt,distancetoBolt from tiger ,tigerAccelaration,boltSpeed
*/