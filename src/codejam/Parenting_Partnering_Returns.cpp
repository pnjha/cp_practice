// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9?show=progress
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int>>> tasks;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	int t,n,a,b;
	cin>>t;

	bool flag = false;
	string ans="";

	for(int v = 0;v<t;v++){

		flag = true;
		ans = "";

		cin>>n;
		tasks.clear();
		tasks.resize(n);

		for(int i = 0;i<n;i++){
			ans += "O";
			cin>>a>>b;
			tasks[i] = {a,{b,i}};
		}

		vector<int> idx;
		sort(tasks.begin(),tasks.end());
		a = 0, b = 0;
		
		for(int i = 0;i<n;i++){
			if(tasks[i].first>=a){
				a = tasks[i].second.first;
				ans[tasks[i].second.second] = 'C';
			}else if(tasks[i].first>=b){
				b = tasks[i].second.first;
				ans[tasks[i].second.second] = 'J';
			}else{
				flag = false;
				break;
			}
		}

		if(!flag)
			cout<<"Case #"<<v+1<<": IMPOSSIBLE\n";
		else
			cout<<"Case #"<<v+1<<": "<<ans<<"\n";
	}

	return 0;
}
