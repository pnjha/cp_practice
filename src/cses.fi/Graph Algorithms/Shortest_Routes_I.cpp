#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<pair<int,ll>>> graph;
vector<ll> dist;
vector<bool> visited;

void dijkstra(){
	
	priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> pq;
	
	pq.push({0,0});
	
	pair<ll,int> temp,child;

	while(!pq.empty()){
		
		temp = pq.top();
		pq.pop();
		
		for(int i = 0;i<graph[temp.second].size();i++){
			
			child = graph[temp.second][i];

			if(dist[child.first] > (dist[temp.second] + child.second)){

				dist[child.first] = (dist[temp.second] + child.second);
								
				pq.push({dist[child.first], child.first});
			}		
		}
	}
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ll n,m,src,dest,weight;
	cin>>n>>m;

	graph.clear();
	graph.resize(n);

	dist.clear();
	dist.resize(n,LONG_MAX);
	dist[0] = 0;

	visited.clear();
	visited.resize(n,false);

	for(int i = 0;i<m;i++){
		cin>>src>>dest>>weight;
		graph[src-1].push_back({dest-1,weight});
	}

	// for(int i = 0;i<graph.size();i++){
	// 	for(int j = 0;j<graph[i].size();j++){
	// 		cout<<graph[i][j].first<<" ";
	// 	}cout<<"\n";
	// }

	dijkstra();

	for(int i = 0;i<dist.size();i++){
		cout<<dist[i]<<" ";
	}

	cout<<"\n";

	return 0;
}
