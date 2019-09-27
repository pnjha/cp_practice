// https://cses.fi/problemset/task/1673

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<pair<int,ll>>> graph;
vector<tuple<int,int,ll>>edge_list;
vector<bool> visited;
vector<ll> dist;

ll bellman_ford(ll source, ll destination, int v, int e, bool& error){

	dist[source] = 0;

	int a,b;
	ll c;

	for(int i = 1;i<v;i++){
		for(int j = 0;j<e;j++){
			
			a = get<0>(edge_list[j]);
			b = get<1>(edge_list[j]);
			c = get<2>(edge_list[j]);
			
			if (dist[a] != INT_MAX && dist[a] + c < dist[b]) 
                dist[b] = dist[a] + c; 
		}

		// for(int i = 0;i<dist.size();i++)
		// 	cout<<dist[i]<<" ";
		// cout<<endl;
	}

	int temp = dist[destination];

	for(int j = 0;j<e;j++){
		
		a = get<0>(edge_list[j]);
		b = get<1>(edge_list[j]);
		c = get<2>(edge_list[j]);
		
		if (dist[a] != INT_MAX && dist[a] + c < dist[b]){
			error = true;
            return -1; 
		}
	}

	// for(int i = 0;i<dist.size();i++)
	// 	cout<<dist[i]<<" ";
	// cout<<endl;

	return dist[destination];
}

bool dfs(int source, int destination){
	
	if(source == destination)
		return true;

	for(int i = 0;i<graph[source].size();i++){
		if(!visited[graph[source][i].first]){
			visited[graph[source][i].first] = true;
			if(dfs(graph[source][i].first,destination))
				return true;
		}
	}

	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<int,bool> unreachable_nodes;
	vector<tuple<int,int,ll>>temp_edge_list;

	int v,e,a,b;
	ll c;
	
	cin>>v>>e;

	edge_list.clear();

	visited.clear();
	visited.resize(v,false);

	graph.clear();
	graph.resize(v);

	dist.clear();
	dist.resize(v,INT_MAX);

	for(int i = 0;i<e;i++){
		cin>>a>>b>>c;
		temp_edge_list.push_back(make_tuple(a-1,b-1,(-1)*c));
		graph[a-1].push_back({b-1,(-1)*c});
	}

	int cnt = 0;

	for(int i = 0;i<v-1;i++){
		visited.clear();
		visited.resize(v,false);
		if(!dfs(i,v-1)){
			if(i == 0){
				cout<<"-1\n";
				return 0;
			}
			unreachable_nodes[i]=true;
			cnt++;
		}
	}

	for(int i = 0;i<temp_edge_list.size();i++){
		if((unreachable_nodes.find(get<0>(temp_edge_list[i]))!=unreachable_nodes.end() && 
			unreachable_nodes[get<0>(temp_edge_list[i])]==true)||
			(unreachable_nodes.find(get<1>(temp_edge_list[i]))!=unreachable_nodes.end() && 
			unreachable_nodes[get<1>(temp_edge_list[i])]==true)){
			continue;
		}
		edge_list.push_back(temp_edge_list[i]);
	}

	bool err = false;
	
	ll d = bellman_ford(0,v-1,v-cnt,edge_list.size(),err);

	if(!err)
		cout<<(-1)*d<<"\n";
	else
		cout<<"-1\n";

	return 0;
}
