#include<bits/stdc++.h>

using namespace std;

vector<string> ans;
vector<bool> visited;

void dfs(string str,string temp,int index){

	if(str.length() == temp.length()){
		ans.push_back(temp);
		return;
	}

	vector<bool> char_done(26,false);

	for(int i = 0;i<str.length();i++){
		if(i!=index&&!visited[i]&&!char_done[str[i]-'a']){
			visited[i] = true;
			char_done[str[i]-'a'] = true;	
			temp += str[i];
			dfs(str,temp,i);
			visited[i] = false;
			temp.pop_back();
		}
	}
}

int main(){

	ios_base::sync_with_stdio(NULL);

	string str;
	cin>>str;

	sort(str.begin(),str.end());

	ans.clear();
	visited.clear();

	visited.resize(str.length(),false);

	string temp = "";
	vector<bool> char_done(26,false);
	
	for(int i = 0;i<str.length();i++){
		if(!char_done[str[i]-'a']){
			char_done[str[i]-'a'] = true;
			temp = str[i];
			visited[i] = true;
			dfs(str,temp,i);
			visited[i] = false;
			temp.pop_back();
		}
	}

	cout<<ans.size()<<"\n";

	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<"\n";
	}

	cout<<"\n";

	return 0;
}
