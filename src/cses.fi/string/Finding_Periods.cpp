// https://cses.fi/problemset/task/1733
#include<bits/stdc++.h>

using namespace std;

int construct_lps(string& str,vector<int>& lps){

	int cnt = 1;
	bool flag = true;

	int i = 1,j = 0;

	while(i<str.length()){

		if(str[i] == str[j]){
			flag = false;
			i++;
			j++;
		}else{
			if(flag)
				cnt++;
			if(j == 0)
				i++;
			else
				j = lps[j-1];
		}
	}

	return cnt;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin>>str;

	vector<int> lps(str.length(),0);

	int cnt = construct_lps(str,lps);
	int i = 0;

	while(cnt*(i+1)<str.length()){
		cout<<cnt*(i+1)<<" ";
		i++;
	}

	cout<<str.length()<<"\n";

	return 0;
}
