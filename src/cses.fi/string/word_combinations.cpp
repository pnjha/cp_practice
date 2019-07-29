#include<bits/stdc++.h>

using namespace std;

unordered_map<string,int> dict;
unordered_map<int, int> memo;

int dfs(string& str,int index){

	if(index == str.length()){
		return 1;
	}
	
	if(memo.find(index)!=memo.end()){	
		return memo[index];
	}

	string temp;
	int t=0,cnt=0;

	for(int i = index;i<str.length();i++){

		temp = str.substr(index,i+1-index);

		cout<<"dfs temp: "<<temp<<"\n";

		if(dict.find(temp)!=dict.end()){
			t = dfs(str,i+1);
			memo[i+1] = t;
			cnt += t;
			cout<<"t: "<<t<<" cnt: "<<cnt<<"\n";
		}
	}	

	memo[index] = cnt;

	return cnt;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int clk = clock();

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string str,temp;
	cin>>str;

	int n,cnt=0,t=0;
	cin>>n;

	for(int i = 0;i<n;i++){
		cin>>temp;
		dict[temp] = true;
	}

	for(int i = 0;i<str.length();i++){

		temp = str.substr(0,i+1);

		cout<<"temp: "<<temp<<"\n";

		if(dict.find(temp)!=dict.end()){
			t = dfs(str,i+1);
			// memo[i+1] = t;
			cnt += t;
			cout<<"t: "<<t<<" cnt: "<<cnt<<"\n";
		}
	}

	cout<<cnt<<"\n";

	cout<<"Time: "<<(clock() - clk)<<"\n";

	return 0;
}