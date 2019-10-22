// https://www.codechef.com/COOK111B/problems/CKWLK
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool dfs(ll n){
	if(n<10){
		if(n == 1) return true;
		else return false;
	}
	return (n%10==0 && dfs(n/10)||n%20==0 && dfs(n/20));
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		bool flag = false;
		if(n<10||n>10&&n<20) flag = false;
		else{
			if(n%10==0 && dfs(n/10) || n%20==0 && dfs(n/20))
				flag = true;
		}

		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}
