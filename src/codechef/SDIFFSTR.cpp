// https://www.codechef.com/AM19MOS/problems/SDIFFSTR
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	char ch[26] = {'a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	ll f,k;
	string s;
	vector<char> t;
	cin>>f;

	while(f--){
		
		int arr[26], temp = 0;
		memset(arr,0,sizeof(arr));
		cin>>s>>k;
		temp = s.length();
		t.clear();
		for(int i = 0;i<s.length();i++){
			arr[s[i]-'a']++;
		}
		for(int i = 0;i<26;i++){
			if(arr[i]==1){
				if(k>0){
					t.push_back(ch[i]);
					k--;	
				}
			}else if(arr[i]==0){
				t.push_back(ch[i]);
			}
			if(t.size()==s.length()) break;
		}
		if(t.size() == s.length()){
			sort(t.begin(),t.end());
			for(int i = 0;i<t.size();i++)
				cout<<t[i];
			cout<<"\n";
		}else{
			cout<<"NOPE\n";
		}
	}

	return 0;
}

/*
4
helowrd 0
background 0
abcdefghijklmnopqrstuvwxyz 0
b 1
*/