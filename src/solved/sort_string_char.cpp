#include<bits/stdc++.h>

using namespace std;

int cnt[26];

bool cmp(char a, char b){
	if(cnt[a-'a']<cnt[b-'a']) return true;
	return false;
}

int main(){
	string s = "bbbccaaaa";
	//output = ccbbbaaaa
	memset(cnt,0,sizeof(26));
	for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
	sort(s.begin(),s.end(),cmp);
	cout<<s<<"\n";
	return 0;
}
