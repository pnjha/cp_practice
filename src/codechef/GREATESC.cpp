// https://www.codechef.com/IARCSJUD/problems/GREATESC/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<ll>> graph;

ll bfs(int s, int d, int m, int n){
	queue<int> q;
	vector<int> distance(n,INT_MAX);
	distance[s] = 0;
	q.push(s);
	ll dist, node;
	while(!q.empty()){
		node = q.front();
		q.pop();
		if(node == d) return distance[d];
		for(int i = 0;i<graph[node].size();i++){
			if(distance[graph[node][i]]>distance[node]+1){
				distance[graph[node][i]] = distance[node]+1;
				q.push(graph[node][i]);
			}
		}
	}
	return INT_MAX;
}

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m,a,b,s,d;
	cin>>n>>m;
	graph.clear();
	graph.resize(n);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cin>>s>>d;
	s--,d--;

	int ans = bfs(s,d,m,n);
	ans = (ans==INT_MAX)?0:ans;
	cout<<ans<<"\n";

	return 0;
}
