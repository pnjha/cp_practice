// https://www.codechef.com/OCT19B/problems/BACREP
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<ll>> graph;
vector<ll> cnt;
vector<bool> visited;

void dfs(int node,int parent){
	
	if(visited[node]) return;

	visited[node] = true;
	bool flag = true;

	for(int i = 0;i<graph[node].size();i++){
		if(!visited[graph[node][i]]){
			flag = false;
			dfs(graph[node][i],node);
		}
	}

	if(flag) cnt[node] += cnt[parent];
	else if(node!=0)	cnt[node] = cnt[parent];
	else cnt[node] = 0;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("input.txt","r",stdin);

	char c;
	ll n,q,a,b;
	cin>>n>>q;

	graph.clear(),graph.resize(n);

	for(int i = 0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cnt.clear(),cnt.resize(n,0);
	for(int i = 0;i<n;i++) cin>>cnt[i];

	while(q--){

		visited.clear(), visited.resize(n,false);
		dfs(0,-1);
		cin>>c;

		if(c == '?'){
			cin>>a;
			a--;
			cout<<cnt[a]<<"\n";
		}else if(c == '+'){
			cin>>a>>b;
			a--;
			cnt[a] += b;
		}
	}
	return 0;
}