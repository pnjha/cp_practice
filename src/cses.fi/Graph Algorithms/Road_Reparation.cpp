// https://cses.fi/problemset/task/1675
#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n){
	parent.clear();
	parent.resize(n,0);
	for(int i = 0;i<n;i++){
		parent[i] = i;
	}
	size.clear();
	size.resize(n,1);
}

int find_root(int a){
	if(parent[a]==a)
		return a;
	return parent[a] = find_root(parent[a]);
}

bool make_union(int a, int b){
	
	int roota = find_root(a);
	int rootb = find_root(b);

	if(roota != rootb){

		if(size[roota]>size[rootb]){

			parent[rootb] = roota;
			size[roota] += size[rootb];

		}else{

			parent[roota] = rootb;
			size[rootb] += size[roota];
		}

	}else{
		return false;
	}
	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	int n,m,a,b,c;
	cin>>n>>m;

	initialize(n);

	vector<pair<int,pair<int,int>>> edges;

	for(int i = 0;i<m;i++){
		cin>>a>>b>>c;
		edges.push_back({c,{a-1,b-1}});
	}

	sort(edges.begin(),edges.end());

	long long cost = 0;

	for(int i = 0;i<m;i++){

		if(make_union(edges[i].second.first,edges[i].second.second))
			cost += edges[i].first;
		// cout<<edges[i].second.first+1<<" "<<edges[i].second.second+1<<" " <<edges[i].first<<"\n";
	
		// for(int j = 0;j<n;j++){
		// 	cout<<parent[j]+1<<" ";
		// }cout<<"\n";
	}

	int cnt = 0;

	for(int i = 0;i<n;i++){
		if(parent[i] == i)
			cnt++;
		// cout<<parent[i]+1<<" ";
	}
	// cout<<"\n";
	// cout<<cnt<<"\n";

	if(cnt == 1)
		cout<<cost<<"\n";
	else
		cout<<"IMPOSSIBLE\n";

	return 0;
}
