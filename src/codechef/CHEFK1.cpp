#include<bits/stdc++.h>
#define ll long double
using namespace std;

int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	ll t, n , m;
	cin>>t;

	while(t--){
		cin>>n>>m;
		
		if(n == 1 && m == 0){
			cout<<"0\n";
		}else if(m<=n-2){
			cout<<"-1\n";
		}else if(n == 2 && m == 1){
			cout<<"1\n";
		}else if(n == 2 && m !=1){
			cout<<"-1\n";
		}else if(m == n-1 || m == n){
			cout<<"2\n";
		}else if((((n-1)*n)/2+n)<m){
			cout<<"-1\n";
		}else{
			// cout<<(double)((2*(m-n))/n)<<"\n";
			// cout<<"ceil "<<ceil((2*(m-n))/n)<<"\n";
			cout<<(ceil((2*(m-n))/n)+1)<<"\n";
		}

	}

	return 0;
}
