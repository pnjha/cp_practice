// https://cses.fi/problemset/task/1672

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll>> graph;

void floyd_warshall(){

	int n = graph.size();

	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if(graph[i][k]!=LONG_MAX && graph[k][j]!=LONG_MAX)
					graph[i][j] = graph[j][i] = min(graph[i][j], graph[i][k]+graph[k][j]);
			}	
		}	
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,m,q,src,dest,weight;
	cin>>n>>m>>q;

	graph.clear();
	graph.resize(n,vector<ll>(n,LONG_MAX));

	for(int i = 0;i<n;i++){
		graph[i][i] = 0;
	}

	for(int i = 0;i<m;i++){
		cin>>src>>dest>>weight;
		graph[src-1][dest-1] = min(graph[src-1][dest-1],weight);
		graph[dest-1][src-1] = min(weight,graph[dest-1][src-1]);
	}

	floyd_warshall();

	for(int i = 0;i<q;i++){
		cin>>src>>dest;
		if(graph[src-1][dest-1]==LONG_MAX)
			cout<<"-1\n";
		else
			cout<<graph[src-1][dest-1]<<"\n";
	}

	return 0;
}
