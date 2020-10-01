// https://cses.fi/problemset/task/1680
//longest path using dijsktra

#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

vector<vector<int>> graph;
vector<int> parent;

bool dijkstra(int& n){

	ll node,d;
	bool flag = false;
	vector<ll> dist(n+1,INT_MIN);
	priority_queue<pair<ll,ll>> pq;
	
	pq.push({0,1});
	dist[1] = 0;

	while(!pq.empty()){

		node = pq.top().second;
		d = pq.top().first;
		pq.pop();

		if(node == n){
			flag = true;
			continue;
		}

		if(node!=n){
			ll l = graph[node].size();
			for(int i = 0;i<l;i++){
				if(dist[graph[node][i]]<dist[node]+1){
					dist[graph[node][i]] = dist[node]+1;
					parent[graph[node][i]] = node;
					pq.push({dist[graph[node][i]],graph[node][i]});
				}
			}
		}
	}

	return flag;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n,m,a,b;

	cin>>n>>m;

	graph.clear();
	graph.resize(n+1);

	parent.clear();
	parent.resize(n+1,-1);	

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		if((a!=b) && (graph[a].size()==0 || graph[a].back()!=b)){	
			graph[a].push_back(b);
		}
	}

	if(dijkstra(n)){

		// for(int i = 1;i<=n;i++)
		// 	cout<<setw(3)<<i<<" ";
		// cout<<"\n";

		// for(int i = 1;i<=n;i++)
		// 	cout<<setw(3)<<parent[i]<<" ";
		// cout<<"\n";

		vector<int> route;

		int i = n;
		while(parent[i]!=-1){
			route.push_back(i);
			i = parent[i];
		}
		
		route.push_back(1);

		cout<<route.size()<<"\n";

		for(int i = route.size()-1;i>=0;i--)
			cout<<route[i]<<" ";
		cout<<"\n";

	}else{
		cout<<"IMPOSSIBLE\n";
	}
	
	return 0;
}
