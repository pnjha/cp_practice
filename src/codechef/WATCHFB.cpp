// https://www.codechef.com/LTIME76B/problems/WATCHFB

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	ll t,n, a,b,c,pa=-1,pb,pc;
	bool flag = false;

	cin>>t;

	while(t--){

		cin>>n;

		while(n--){

			cin>>a>>b>>c;

			if(b == c){
				flag = false;
				cout<<"YES\n";		
						
			}else if(a == 1){

				flag = false;
				cout<<"YES\n";

			}else if(a == 2){

				if(pa == 2 && flag){
					flag = true;
					cout<<"NO\n";
				
				}else if(pa == -1){
					flag = true;
					cout<<"NO\n";
				
				}else{

					if(max(pb,pc)<=min(b,c)){
						flag = true;
						cout<<"NO\n";
					}else if(pb<=b&&pc<=c || pb<=c&&pc<=b){
						flag = false;
						cout<<"YES\n";
					}else{
						flag = true;
						cout<<"NO\n";
					}
				}
			}
			
			pa = a,pb = b,pc = c;
		}

	}

	return 0;
}
