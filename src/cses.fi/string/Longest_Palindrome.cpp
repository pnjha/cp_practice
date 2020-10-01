// https://cses.fi/problemset/task/1111

#include<bits/stdc++.h>

using namespace std;

string manacher_pallindrome(string& s){

	int n = s.length()*2+4;

	char ch[n];

	ch[0] = '@';
	ch[n-2] = '&';
	ch[n-1] = '\0';

	for(int i = 1;i<n-2;i++){
		if(i%2==0)
			ch[i] = s[i/2-1];
		else
			ch[i] = '#';
	}

	string str(ch);
	int c=0,r=0,mirr=0;
	vector<int> len(n,0);

	for(int i = 1;i<n-1;i++){

		mirr = 2*c - i;
		if(i<r){
			len[i] = min(r-i,len[mirr]);
		}

		while(str[i-(1+len[i])] == str[i+(1+len[i])])
			len[i]++;

		if(i+len[i] > r){
			c = i;
			r = i+len[i];
		}
	}

	int max_index = -1,max_val = INT_MIN;
	for(int i = 0;i<len.size();i++){
		if(max_val<=len[i]){
			max_index = i;
			max_val = len[i];
		}
	}

	char cc[max_val+1];
	cc[max_val] = '\0';
	int i = 0,j = 0;

	// if(str[max_index]=='#'){
	// 	i = 0;
	// 	j =  ;
	// }else{
		i = 0;
		j = max_index - (max_val-1);
		while(j<(max_index + max_val)){
			if(str[j]!='#'){
				cc[i] = str[j];
				i++;
			}
			j++;
		}	
	// }

	return string(cc);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin>>s;

	cout<<manacher_pallindrome(s)<<"\n";

	return 0;
}
