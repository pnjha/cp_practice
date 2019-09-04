// https://online.codingblocks.com/player/33819/content/13653/5097

#include<bits/stdc++.h>

using namespace std;

vector<unordered_map<int,int>> graph;
vector<bool> explored;
vector<int> distances;

void dijsktra(int source){

	distances[source] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({0,source});

	int dist = 0,parent = -1;

	while(!pq.empty()){

		parent = pq.top().second;
		dist = pq.top().first;

		pq.pop();

		explored[parent] = true;

		for(auto node: graph[parent]){

			if(!explored[node.first]){

				if(distances[node.first] > distances[parent] + graph[parent][node.first]){

					distances[node.first] = distances[parent] + graph[parent][node.first];

					pq.push({distances[node.first], node.first});
				}
			}
		}
	}
}

int main(){

	int t,n,m,a,b,c;

	cin>>t;

	while(t--){

		cin>>n>>m;

		graph.clear();

		explored.clear();
		explored.resize(n+1,false);

		distances.clear();
		distances.resize(n+1,INT_MAX);

		for(int i = 0;i<m;i++){
			cin>>a>>b>>c;
			if(graph[a].find(b)!=graph[a].end() && c >= graph[a][b]){
				continue;
			}
			graph[a][b] = c;
			graph[b][a] = c;
		}

		int source = -1;
		cin>>source;

		dijsktra(source);

		for(int i = 1;i<n+1;i++){
			if(i != source){
				if(distances[i]!=INT_MAX)
					cout<<distances[i]<<" ";
				else
					cout<<"-1\n";
			}	
		}
		cout<<"\n";
	}

	return 0;
}
