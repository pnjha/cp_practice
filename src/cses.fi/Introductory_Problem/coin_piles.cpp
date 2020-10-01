#include<bits/stdc++.h>

using namespace std;

int main(){

	long double t,n,m;
	cin>>t;

	while(t--){

		cin>>n>>m;

		if(n==0&&m==0){
			cout<<"YES\n";
			continue;
		}

		if(n==0||m==0){
			cout<<"NO\n";
			continue;
		}
		
		long double x = (((long double)(n * 2) - m)/3);
		long double y = (((long double)(m * 2) - n)/3);

		// cout<<x<<" "<<y<<"\n";
		// cout<<y-(long double)(round(y))<<" "<<x-(long double)(round(x))<<endl;
		// if(ceil(x - (long long int)(x))<=1e-15&&ceil(round(y) - (long long int)(y))<=1e-15)
		if(fabs(y-(long double)(round(y)))<=1e-15 && fabs(x-(long double)(round(x)))<=1e-15 && x>=0 && y>=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}