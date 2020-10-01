// https://www.codechef.com/JUNE20B/problems/XYSTR
#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;

	while(t--){

		string str;
		cin>>str;
		int cnt = 0, left = 0, right = 1;

		while(right<str.length()){
			if((str[left]=='x'&&str[right]=='y') || (str[left]=='y'&&str[right]=='x')){
				left = right+1;
				right += 2;
				cnt++;
			}else{
				left++;
				right++;
			}
		}

		cout<<cnt<<"\n";
	}


	return 0;
}

/*
3
xy
xyxxy
yy
*/