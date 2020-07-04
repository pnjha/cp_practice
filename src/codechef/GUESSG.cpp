// https://www.codechef.com/JUNE20B/problems/GUESSG
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ll n,ao=0,bo=0,go=0,ae=0,be=0,ge=0;
	cin>>n;
	char so,se;
	bool even_flag=true, odd_flag=true;

	ao = 1, bo = n, go = 0;
	ae = 1, be = n, ge = 0;
	while(true){
		
		go = ao + (bo-ao)/2;
		if(!odd_flag)
			cout<<"1\n";
		else
			cout<<go<<"\n";
		cin>>so;
		if(so == 'E') return 0;

		ge = ae + (be-ae)/2;
		if(!even_flag)
			cout<<"1\n";
		else
			cout<<ge<<"\n";
		cin>>se;
		if(se == 'E') return 0;

		if((ao == bo && so != 'E') || (ao>bo) || ao>n || bo<1) odd_flag = false;
		if((ae == be && se != 'E') || (ae>be) || ae>n || be<1) even_flag = false;
		
		if(!odd_flag && !even_flag) return 0;

		if(so == 'L') ao = go+1;
		else if(so == 'G') bo = go-1;
		
		if(se == 'L') ae = ge+1;
		else if(se == 'G') be = ge-1;
	}
	return 0;
}