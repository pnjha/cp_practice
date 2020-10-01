// https://www.codechef.com/OCT19B/problems/BACREP
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<ll>> graph;
vector<ll> cnt;

void dfs(int node,int& t){
	if(cnt[node]!=-1) return;
	cnt[node] = t;
	t++;
	for(int i = 0;i<graph[node].size();i++)
		if(cnt[graph[node][i]]==-1) dfs(graph[node][i],t);
}

vector<vector<ll>> reorder_graph(){

	int n = graph.size(),t = 0;
	vector<map<ll,bool>> ng(n);
	vector<vector<ll>> new_graph(n);
	cnt.clear(),cnt.resize(n,-1);

	dfs(0,t);

	for(int i = 0;i<n;i++){
		for(int j = 0;j<graph[i].size();j++){
			if(cnt[i]<cnt[graph[i][j]]) ng[i][graph[i][j]] = true;
		}
	}

	for(int i = 0;i<n;i++){
		for(auto x : ng[i]) new_graph[i].push_back(x.first);
	}
	return new_graph;
}

void make_tranfer(){

	int n = cnt.size();
	vector<ll> new_cnt(n,0);
	
	for(int i = 0;i<n;i++){
		if(graph[i].size()>0){			
			for(int j = 0;j<graph[i].size();j++) new_cnt[graph[i][j]] = cnt[i];
		}
		else new_cnt[i] += cnt[i];
		cnt[i] = 0;
	}
	cnt.clear();
	cnt = new_cnt;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt","r",stdin);

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

	graph = reorder_graph();

	// for(int i = 0;i<n;i++){
	// 	cout<<i<<" : ";
	// 	for(int j = 0;j<graph[i].size();j++){
	// 		cout<<graph[i][j]<<" ";
	// 	}cout<<"\n";
	// }

	cnt.clear(),cnt.resize(n,0);
	for(int i = 0;i<n;i++) cin>>cnt[i];

	while(q--){

		make_tranfer();
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

		for(int i = 0;i<n;i++)
			cout<<cnt[i]<<" ";
		cout<<"\n";
	}
	return 0;
}