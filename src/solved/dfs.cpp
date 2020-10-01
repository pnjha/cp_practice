#include<bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<pair<int,int>>> graph;

void dfs(int index){
	cout<<index<<" ";
	visited[index] = true;
	for(int i=0;i<graph[index].size();i++){
		if(visited[graph[index][i].first]==false){
			dfs(graph[index][i].first);
		}
	}	
}

int main(){
	cout<<"dfs\n";
	int vertices,edges,weight;
	cin>>vertices>>edges;

	visited.assign(vertices,false);
	graph.assign(vertices,vector<pair<int,int>>());
	int a,b;
	for(int i=0;i<edges;i++){
		cin>>a>>b>>weight;
		graph[a].push_back(make_pair(b,weight));
		//graph[b].push_back(a);  //comment this line for directed graph
	}

	for(int i=0;i<vertices;i++){
		if(visited[i]==false){
			dfs(i);
		}
	}
	cout<<"\n";
	return 0;
}