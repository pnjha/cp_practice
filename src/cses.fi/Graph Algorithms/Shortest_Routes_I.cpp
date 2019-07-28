#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,unsigned long long int>>> graph;
vector<unsigned long long int> dist;
vector<bool> visited;

void dijkstra(){
	
	priority_queue<pair<unsigned long long int,int> , vector<pair<unsigned long long int,int>> , greater<pair<unsigned long long int,int>>> pq;
	
	pq.push({0,0});
	
	pair<unsigned long long int,int> temp,child;

	while(!pq.empty()){
		
		/*
		for(int i = 0;i<dist.size();i++)
			cout<<dist[i]<<" ";
		cout<<"\n";
	
		for(int i = 0;i<visited.size();i++)
			cout<<visited[i]<<" ";
		cout<<"\n";
		*/

		temp = pq.top();
		pq.pop();
		//visited[temp.second] = true;
		//dist[temp.second] = min(temp.first,dist[temp.second]);
		
		for(int i = 0;i<graph[temp.second].size();i++){
			
			child = graph[temp.second][i];

			//if(visited[child.first]==false){

				if(dist[child.first] > (dist[temp.second] + child.second)){

					dist[child.first] = (dist[temp.second] + child.second);
									
					pq.push({dist[child.first], child.first});
				}	
			//}	
		}
	}
}

int main(){

	unsigned long long int n,m,src,dest,weight;
	cin>>n>>m;

	graph.clear();
	graph.resize(n);

	dist.clear();
	dist.resize(n,INT_MAX);
	dist[0] = 0;

	visited.clear();
	visited.resize(n,false);

	for(int i = 0;i<m;i++){
		cin>>src>>dest>>weight;
		graph[src-1].push_back({dest-1,weight});
	}


	dijkstra();

	for(int i = 0;i<dist.size();i++){
		cout<<dist[i]<<" ";
	}

	cout<<"\n";

	return 0;
}
