// https://www.codechef.com/LTIME76B/problems/PAIRSUM2

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	ll t,n,q,a,b;

	cin>>t;

	vector<ll> B;
	vector<ll> even;
	vector<ll> odd;

	while(t--){

		cin>>n>>q;

		B.clear();
		B.resize(n,0);

		odd.clear();
		odd.resize(n,0);

		even.clear();
		even.resize(n,0);

		for(int i = 1;i<n;i++){
			cin>>B[i];
			if(i&1){
				odd[i] = odd[i-1]+B[i];
				even[i] = even[i-1]-B[i];
			}else{
				even[i] = even[i-1]+B[i];
				odd[i] = odd[i-1]-B[i];
			}
		}

		while(q--){

			cin>>a>>b;

			if(abs(a-b)%2==0){
				cout<<"UNKNOWN\n";
			}else{
				if(abs(a-b)==1){
					cout<<B[floor((a+b)/2)]<<"\n";
				}else{
					ll sum = 0, r = min(a,b),s = max(a,b)-1;
					
					if(r&1){
					
						sum = (odd[s] - odd[r-1]);

					}else{

						sum = (even[s] - even[r-1]);
					}

					cout<<sum<<"\n";
				}
			}
		}

	}

	return 0;
}
