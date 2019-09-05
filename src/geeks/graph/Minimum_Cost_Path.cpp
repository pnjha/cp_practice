// https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
#include<bits/stdc++.h>
#define INF 1e5+7
using namespace std;

vector<vector<int>> graph;

int disjktra(int source,int destination){

	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

	vector<vector<int>> distances(graph.size(),vector<int>(graph.size(), INF));
	vector<vector<bool>> explored(graph.size(),vector<bool>(graph.size(), false));

	explored[source][source] = true;
	pq.push({graph[source][source],{source,source}});

	int dist = 0;
	pair<int,int> parent;

	while(!pq.empty()){

		parent = pq.top().second;
		dist = pq.top().first;
		pq.pop();

		// cout<<parent<<"\n";

		distances[parent.first][parent.second] = dist;
		explored[parent.first][parent.second] = true;

		if(parent.first == destination && parent.second == destination){
			break;
		}

		if(parent.first-1>=0&&!explored[parent.first-1][parent.second]){
			if(distances[parent.first-1][parent.second] > distances[parent.first][parent.second] + graph[parent.first-1][parent.second]){
				distances[parent.first-1][parent.second] = distances[parent.first][parent.second] + graph[parent.first-1][parent.second];
				pq.push({distances[parent.first-1][parent.second],{parent.first-1,parent.second}});
			}
		}
		if(parent.second-1>=0&&!explored[parent.first][parent.second-1]){
			if(distances[parent.first][parent.second-1] > distances[parent.first][parent.second] + graph[parent.first][parent.second-1]){
				distances[parent.first][parent.second-1] = distances[parent.first][parent.second] + graph[parent.first][parent.second-1];
				pq.push({distances[parent.first][parent.second-1],{parent.first,parent.second-1}});
			}	
		}
		if(parent.first+1<graph.size()&&!explored[parent.first+1][parent.second]){
			if(distances[parent.first+1][parent.second] > distances[parent.first][parent.second] + graph[parent.first+1][parent.second]){
				distances[parent.first+1][parent.second] = distances[parent.first][parent.second] + graph[parent.first+1][parent.second];
				pq.push({distances[parent.first+1][parent.second],{parent.first+1,parent.second}});
			}
		}
		if(parent.second+1<graph.size()&&!explored[parent.first][parent.second+1]){
			if(distances[parent.first][parent.second+1] > distances[parent.first][parent.second] + graph[parent.first][parent.second+1]){
				distances[parent.first][parent.second+1] = distances[parent.first][parent.second] + graph[parent.first][parent.second+1];
				pq.push({distances[parent.first][parent.second+1],{parent.first,parent.second+1}});
			}
		}
	}

	// for(int i = 0;i<distances.size();i++)
	// 	cout<<distances[i]<<" ";
	// cout<<"\n";

	return distances[destination][destination];
}

int main(){

	int t,n,a;
	cin>>t;

	while(t--){

		cin>>n;



		graph.clear();
		graph.resize(n,vector<int>(n,0));

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>graph[i][j];
			}
		}

		int source = 0, destination = n-1;

		cout<<disjktra(source,destination)<<"\n";
	}

	return 0;
}
