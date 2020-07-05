#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> reGraph;
vector<int> visited;
stack<int> stackVertex;


void printStronglyConnectedComponent(int index){
	visited[index] = 1;
	cout<<index<<" ";
	for(int i=0;i<reGraph[index].size();i++){
		if(visited[reGraph[index][i]]==0)
			printStronglyConnectedComponent(reGraph[index][i]);
	}	
}


void fillStack(int index){

	visited[index] = 1;

	for(int i=0;i<graph[index].size();i++){
		if(visited[graph[index][i]]==0)
			fillStack(graph[index][i]);
	}

	stackVertex.push(index);
}


int main(){
	
	int vertices,edges;
	cin>>vertices>>edges;
	graph.resize(vertices);
	reGraph.resize(vertices);
	visited.resize(vertices,0);
	int v1,v2;

	for(int i=0;i<edges;i++){
		cin>>v1>>v2;
		graph[v1-1].push_back(v2-1);
		reGraph[v2-1].push_back(v1-1);
	}

	for(int i=0;i<vertices;i++){
		if(visited[i]==0){
			fillStack(i);
		}	
	}
	
	visited.assign(vertices,0);

	while(stackVertex.empty()==false){
		if(visited[stackVertex.top()]==0){
			printStronglyConnectedComponent(stackVertex.top());
			cout<<"\n";
		}
		stackVertex.pop();	
	}



	return 0;
}