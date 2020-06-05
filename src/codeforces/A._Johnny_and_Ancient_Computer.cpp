// https://codeforces.com/contest/1362/problem/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int count_setbits(ll a){
	int cnt = 0;
	while(a){
		if(a&1) cnt++;
		a >>= 1;
	}
	return cnt;
}

int main(){

	// freopen("input.txt","r",stdin);

	ll t,a,b;
	cin>>t;

	while(t--){

		cin>>a>>b;
		ll s = 0;
		if(a == b) cout<<"0\n";
		else{
			// cout<<a<<":"<<count_setbits(a)<<" "<<b<<":"<<count_setbits(b)<<"\n";
			if(count_setbits(a)!=count_setbits(b)) cout<<"-1\n";
			else{
				if(a>b){
					while(true){
						if(a%8==0) a /= 8;
						else if(a%4==0) a /= 4;
						else if(a%2==0) a /= 2;
						s++;
						if(a<=b) break; 
					}
				}else if(a<b){
					while(true){
						// cout<<a<<" "<<b<<"\n";
						if(a*8<=b) a *= 8;
						else if(a*4<=b) a *= 4;
						else if(a*2<=b) a *= 2;
						s++;
						if(a>=b || a<0) break; 
					}
				}
				if(a == b) cout<<s<<"\n";
				else cout<<"-1\n";
			}
		}
	}


	return 0;
}
