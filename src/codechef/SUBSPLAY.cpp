// https://www.codechef.com/DEC19B/problems/SUBSPLAY
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t,n;
	string s;

	cin>>t;
	
	while(t--){
		cin>>n;
		cin>>s;
		ll ind[26], diff[26];
		memset(ind,-1,sizeof(ind));
		for(int i=0;i<26;i++) diff[i] = INT_MAX;
		for(int i=0;i<s.length();i++){
			if(ind[s[i]-'a']!=-1) diff[s[i]-'a'] = min(diff[s[i]-'a'],i-ind[s[i]-'a']-1);
			ind[s[i]-'a'] = i;
		}
		ll m = INT_MAX;
		for(int i=0;i<26;i++) m = min(m,diff[i]);
		if(m == INT_MAX) cout<<"0\n";
		else cout<<s.length()-m-1<<"\n";
	}

	return 0;
}
