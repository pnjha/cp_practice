// https://cses.fi/problemset/task/1679
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<bool> explored;
vector<int> ans;
bool flag = false;

void dfs(int index){

	if(index>=explored.size() || explored[index])
		return;
	
	visited[index] = true;

	for(int i = 0;i<graph[index].size();i++){
		if(!visited[graph[index][i]])
			dfs(graph[index][i]);
		else{
			flag = true;
			return; 
		}
	}

	visited[index] = false;
	explored[index] = true;
	ans.push_back(index);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n,m,a,b;
	cin>>n>>m;

	flag = false;

	ans.clear();

	explored.clear();
	explored.resize(n+1,false);

	visited.clear();
	visited.resize(n+1,false);

	graph.clear();
	graph.resize(n+1);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
	}

	for(int i = 1;i<visited.size();i++){
		if(!explored[i]){
			dfs(i);
		}
	}

	if(flag){

		cout<<"IMPOSSIBLE\n";

	}else{

		reverse(ans.begin(),ans.end());

		for(int i = 0;i<n;i++){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}

	return 0;
}
