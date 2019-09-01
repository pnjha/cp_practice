//https://www.spoj.com/problems/LPS/
#include<bits/stdc++.h>

using namespace std;

void manacher_pallindrom(string &a){

	int n = a.length()*2+4;

	// 012345678910
	// @#a#b#a#b#a #&\0

	char s[n]; 

	s[0] = '@';
	s[n-2] = '&';
	s[n-1] = '\0';

	for(int i = 1;i<n-2;i++){
		if(i%2==0)
			s[i] = a[floor(i/2)-1];
		else
			s[i] = '#';
	}

	string str(s);
	// cout<<n<<" "<<str<<"\n";

	vector<int> len(str.length(),0);
	int center_position=0,right_boundary=0,mirror_position;

	for(int i = 1;i<str.length()-1;i++){

		mirror_position = 2 * center_position - i;
		
		if(i<right_boundary)
			len[i] = min(right_boundary - i,len[mirror_position]);

		while(str[i-(1+len[i])] == str[i+(1+len[i])])
			len[i]++;

		if(i+len[i] > right_boundary){
			center_position = i;
			right_boundary = i+len[i];
		}
	}

	int max_len = INT_MIN,max_index = -1;

	for(int i = 0;i<len.size();i++){
		if(max_len<len[i]){
			max_index = i;
			max_len = len[i];
		}
	}

	// cout<<max_index<<"\n";
	cout<<max_len<<"\n";
}

int main(){

	int n;
	cin>>n;

	string a;
	cin>>a;

	manacher_pallindrom(a);

	return 0;
}
