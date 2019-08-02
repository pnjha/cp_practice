#include<bits/stdc++.h>

using namespace std;

vector<string> ans;

void dfs(string s,int left, int right){

	// cout<<s<<" "<<left<<" "<<right<<"\n";

	if(right<left || left<0)
		return;

	if(right == 0){
		ans.push_back(s);
		return;
	}

	dfs(s + "(", left-1,right);
	dfs(s + ")", left,right-1);
}

int main(){

	int n;
	cin>>n;

	ans.clear();

	dfs("",n,n);
	reverse(ans.begin(),ans.end());
	for(int i = 0;i<ans.size();i++)
		cout<<ans[i]<<"\n";

	return 0;
}