// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/black-707332fc/
#include<bits/stdc++.h>
#define ll long long int
#define tl tuple<ll,int,int,int>

using namespace std;

vector<vector<ll>> graph;
vector<bool> visited;
vector<int> color;
ll ans;

void dfs(ll n, ll black_cnt, ll white_cnt, int node, ll cost){

	if(visited[node]) return;
	if(node == n-1 && abs(black_cnt - white_cnt) <= 1) { ans = min(ans, cost); return; }

	visited[node] = true;

	for(int i = 0;i<n;i++){
		if(graph[node][i]!=-1 && !visited[i]){
			if(color[i]==0) dfs(n,black_cnt+1,white_cnt,i,cost+graph[node][i]);
			else dfs(n,black_cnt,white_cnt+1,i,cost+graph[node][i]);
		}
	}

	visited[node] = false;	
}

void dijkstra(int source, int destination, int n){

	priority_queue<tl, vector<tl>, greater<tl>> pq;
	vector<ll> dist(n,LONG_MAX);
	int node, bcnt, wcnt;
	ll d;
	
	dist[source] = 0;
	if(color[source] == 0) pq.emplace(0,source,1,0);
	else pq.emplace(0,source,0,1);

	while(!pq.empty()){

		tie(d,node,bcnt,wcnt) = pq.top(), pq.pop();

		cout<<node<<"\n";

		if(node == destination) cout<<bcnt<<" "<<wcnt<<"\n";

		if(node == destination && abs(bcnt-wcnt)<=1) { ans = d; return; }
		visited[node] = true;

		for(int i = 0;i<n;i++){
			if(graph[node][i]!=-1 && !visited[i]){
				if(dist[i]>dist[node]+graph[node][i]){
					dist[i] = dist[node]+graph[node][i];
					if(color[i] == 0) pq.emplace(dist[i],i,bcnt+1,wcnt);
					else if(color[i] == 1) pq.emplace(dist[i],i,bcnt,wcnt+1);				
					// cout<<i<<" "<<dist[i]<<" "<<color[i]<<"\n";
				}
			}
		}
	}
}

int main(){

	freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	ll n,m,a,b,c;
	cin>>n>>m;

	ans = LONG_MAX;
	graph.clear(), graph.resize(n,vector<ll>(n,-1));
	color.clear(), color.resize(n);
	visited.clear(), visited.resize(n,false);

	for (int i = 0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		graph[a][b] = c, graph[b][a] = c;
	}

	for(int i = 0;i<n;i++) cin>>color[i];

	dijkstra(0,n-1,n);

	// if(color[0] == 0) dfs(n,1,0,0,0);
	// else dfs(n,0,1,0,0);

    if(ans == LONG_MAX) ans = -1;
	cout<<ans<<"\n";
	return 0;
}
