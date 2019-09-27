// https://cses.fi/problemset/task/1668
//graph coloring problem check bipartite graph

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> color;
vector<bool> visited;

bool dfs(int node,int c){	

	color[node] = c;
	visited[node] = true;

	for(int i = 0;i<graph[node].size();i++){
		if(color[graph[node][i]]==c){
			return false;
		}
		if(!visited[graph[node][i]]){
			if(!dfs(graph[node][i], 1-c)){
				return false;
			}
		}
	}

	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,a,b;
	cin>>n>>m;

	graph.clear();
	graph.resize(n);

	visited.clear();
	visited.resize(n,false);

	color.clear();
	color.resize(n,-1);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	int c = 0; 

	for(int i = 0;i<n;i++){
		
		if(color[i] == -1){
			if(dfs(i,c)){
				c = 1-c;
			}else{
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	for(int i = 0;i<n;i++)
		cout<<color[i]+1<<" ";
	cout<<"\n";

	return 0;
}
