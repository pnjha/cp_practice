#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
stack<int> stackVertex;

void topologicalSort(int index){

	visited[index] = 1;

	for(int i=0;i<graph[index].size();i++){
		cout<<index<<" "<<graph[index][i]<<"\n";
		if(visited[graph[index][i]] != 1)
			topologicalSort(graph[index][i]);
	}

	stackVertex.push(index);
}


int main(){
	
	int vertices,edges;
	cin>>vertices>>edges;
	graph.resize(vertices);
	visited.resize(vertices,0);
	int v1,v2;

	for(int i=0;i<edges;i++){
		cin>>v1>>v2;
		graph[v1].push_back(v2);
	}

	for(int i=0;i<vertices;i++){

		if(visited[i]==0){
			topologicalSort(i);
		}	
	}
	

	for(int i=vertices-1;i>=0;i--){
		cout<<stackVertex.top()<<" ";
		stackVertex.pop();
	}
	cout<<"\n";

	return 0;
}