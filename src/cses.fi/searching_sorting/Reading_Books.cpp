// https://cses.fi/problemset/task/1631

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,a,max_ele=INT_MIN,s= 0;

	cin>>n;

	while(n--){
		cin>>a;
		max_ele = max(max_ele,a);
		s += a;
	}

	cout<<((max_ele>(s - max_ele)?(2*max_ele):s))<<"\n";

	return 0;
}
