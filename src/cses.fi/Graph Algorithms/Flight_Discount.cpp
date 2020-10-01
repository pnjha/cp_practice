// https://cses.fi/problemset/task/1195

#include<bits/stdc++.h>
#define ll long long int
#define tlll tuple<ll,ll,ll>
#define tll tuple<ll,ll>
#define LONG_MAX 1ll<<62

using namespace std;

void dijkstra(ll source,vector<ll>& dist, vector<vector<tll>>& graph){

	priority_queue<tll, vector<tll>, greater<tll>> pq;

	dist[source] = 0;

	pq.push({0ll,source});

	ll d = 0,node = -1,a,b;

	while(!pq.empty()){

		tie(d,node) = pq.top();
		pq.pop();

		if(dist[node]<d)
			continue;

		for(int i = 0;i<graph[node].size();i++){

			tie(a,b) = graph[node][i];

			if(dist[a]>dist[node]+b){
				dist[a] = dist[node]+b;
				pq.push({dist[a],a});
			}
		}
	}
}

int main(){

	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,m,a,b,c;
	cin>>n>>m;

	vector<vector<tll>> graph_source(n), graph_destination(n);
	vector<tlll> edges;
	vector<ll> d_source(n,LONG_MAX), d_destination(n,LONG_MAX);

	for(int i = 0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		graph_source[a].push_back({b,c});
		graph_destination[b].push_back({a,c});
		edges.emplace_back(a,b,c);
	}

	dijkstra(0,d_source,graph_source);
	dijkstra(n-1,d_destination,graph_destination);

	d_source[0] = d_destination[n-1] = 0;

	ll min_val = LONG_MAX;

	for(auto x : edges){
		tie(a,b,c) = x;
		min_val = min(min_val, d_source[a]+d_destination[b]+c/2);
	}

	cout<<min_val<<"\n";

	return 0;
}
