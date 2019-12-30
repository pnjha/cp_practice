// https://www.codechef.com/LTIME79A/problems/EVIPRO
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	ll t,ans = 0;
	cin>>t;

	string s,temp;

	while(t--){

		cin>>s;
		ans = 0;

		for(int i = 0;i<s.length();i++){
			for(int j = i;j<s.length();j++){	
				temp = s;
				for(int k = i;k<=j;k++){
					s[k] = (s[k]=='0'?'1':'0');
				}
				for(int k = 0;k<s.length()-1;k++){
					if(s[k] == s[k+1]){
						ans++;
					} 
				}
				s = temp;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
