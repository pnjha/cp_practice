// https://cses.fi/problemset/task/1753/
#include<bits/stdc++.h>

using namespace std;

void construct_lps(string& pattern, vector<int>& lps){

	lps[0] = 0;
	int i = 1,j = 0;

	while(i<lps.size()){

		if(pattern[i] == pattern[j]){

			lps[i] = j+1;
			i++;
			j++;
		}else{

			if(j == 0)
				i++;
			else{
				j = lps[j-1];
			}
		}
	}
}

int find_substring(string& a, string& b){

	vector<int> lps(b.length(),0);

	construct_lps(b,lps);
	// cout<<"lps: \n";
	// for(int i = 0;i<lps.size();i++){
	// 	cout<<lps[i]<<" ";
	// }cout<<"\n";



	int cnt = 0;
	// a += "&";

	for(int i = 0,j = 0;i<a.length()&&j<b.length();){

		if(a[i] == b[j]){
			
			if(j == b.length()-1){
				cnt++;
				// cout<<i<<" "<<j<<"\n";
				// i = i - lps[j-1];
				// j == 0;
				// j++;
				// i++;
				if(j!=0)
					j = lps[j-1];
				else
					i++;
				// cout<<cnt<<"\n";
			}else{
				i++;
				j++;
			}
		}else{
			if(j==0)
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

	// freopen("input.txt","r",stdin);

	string a,b;

	cin>>a>>b;

	if(a == b){
		cout<<"1\n";
	}else{
		cout<<find_substring(a,b)<<"\n";
	}

	return 0;
}
