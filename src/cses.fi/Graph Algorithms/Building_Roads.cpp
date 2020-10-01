// https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>

using namespace std;

vector<int> parent, node_rank;

void initialize_dsu(int n){

	parent.clear();
	node_rank.clear();

	parent.resize(n+1);

	for(int i = 1;i<=n;i++)
		parent[i] = i;

	node_rank.resize(n+1,1);
}

int find_root(int a){

	while(parent[a]!=a){
		parent[a] = parent[parent[a]];
		a = parent[a];
	}
	return a;
}

void make_union(int a, int b){

	int root_a = find_root(a);
	int root_b = find_root(b);

	if(node_rank[root_a] > node_rank[root_b]){

		parent[root_b] = root_a;
		node_rank[root_a] += node_rank[root_b];

	}else{

		parent[root_a] = root_b;
		node_rank[root_b] += node_rank[root_a];
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,a,b;
	cin>>n>>m;

	initialize_dsu(n);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		make_union(a,b);
	}

	unordered_map<int,bool>ump;
	int prev = -1,cnt = 0;

	for(int i = 1;i<parent.size();i++){
		if(parent[i] == i)
			ump[parent[i]] = true;
	}

	cout<<ump.size()-1<<"\n";

	for(auto itr = ump.begin();itr!=ump.end();itr++){
		if(prev==-1){
			prev = itr->first;
		}else{
			cout<<prev<<" "<<itr->first<<"\n";
			prev = itr->first;
		}
	}

	return  0;
}
