// https://codeforces.com/problemset/problem/339/A
#include<bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin>>s;
	// cout<<s<<"\n";
	int one=0, two=0, three=0, cnt=0;
	for(int i = 0;i<s.length();i++){
		if(s[i]=='1') one++;
		else if(s[i]=='2') two++;
		else if(s[i]=='3') three++;
	} 

	cnt = one + two + three;

	for(int i = 0;i<cnt;i++){
		if(one>0){
			one--;
			cout<<"1";
		} 
		else if(two>0){
			two--;
			cout<<"2";
		}
		else if(three>0){
			three--;
			cout<<"3";
		}
		if(i!=cnt-1) cout<<"+";
	}

	return 0;
}
