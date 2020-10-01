// https://www.codechef.com/LTIME79A/problems/CHEALG
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

		string s,temp,n="";
		cin>>s;
		int cnt = 1;
		char curr = s[0];
		for(int i = 1;i<s.length();i++){
			if(s[i] == curr) cnt++;
			else{
				n += curr + to_string(cnt);
				cnt = 1;
				curr = s[i];
			}
		}

		n += curr + to_string(cnt);
		// cout<<s<<" "<<n<<"\n";

		if(s.length()>n.length()) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
