// https://codeforces.com/problemset/problem/1230/B

#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	if((n == 1&&k>0))
		cout<<"0\n";
	else{
		if(k>0){
			if(s[0]!='1'){				
				k--;
				s[0] = '1';
			}
			int i = 1;
			while(k>0 && i<n){
				if(s[i]!='0'){
					s[i] = '0';
					k--;
				}
				i++;
			}
		}
		cout<<s<<"\n";
	}

	return 0;
}
