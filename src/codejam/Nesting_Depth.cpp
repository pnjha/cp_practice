// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f?show=progress
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	string ans,in,temp;
	int t;
	cin>>t;
	for(int v = 0;v<t;v++){

		ans = "";
		temp = "";
		cin>>in;

		for(int i = 0;i<in.length();i++){
			int k = in[i] - '0';
			for(int j = 0;j<k;j++) temp += '(';
			temp += in[i];
			for(int j = 0;j<k;j++) temp += ')';		
		}

		// cout<<temp<<"\n";
		stack<char> s;

		for(int i = 0;i<temp.length();i++){			
			if(!s.empty()&&temp[i]=='('&&s.top()==')')
				s.pop();
			else{
				s.push(temp[i]);	
			}			
		}
		ans = "";
		// cout<<s.size()<<"\n";
		while(!s.empty()){
			ans += s.top();
			s.pop();
		}

		reverse(ans.begin(),ans.end());

		cout<<"Case #"<<v+1<<": "<<ans<<"\n";
	}


	return 0;
}
