// https://codeforces.com/contest/1287/problem/A
#include<bits/stdc++.h>

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin>>t;

	while(t--){

		int k,ans = 0;
		string s,p,temp;
		cin>>k;
		cin>>s;
		p = s;	
		while(true){

			temp = s;
			for(int i = 0;i<k-1;i++){
				if(s[i]=='A') temp[i+1] = 'A';
			}
			s = temp;
			if(p == s) break;
			ans++;
			p = s;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
