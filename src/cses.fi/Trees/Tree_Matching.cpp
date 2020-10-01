// https://cses.fi/problemset/task/1130
#include<bits/stdc++.h>

using namespace std;


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input","r",stdin);

	int n,a,b,ans = 0;
	cin>>n;
	set<int> nodes;
	vector<int> degree(n,0);
	vector<vector<int>> tree(n);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	for(int i = 0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
		degree[a]++, degree[b]++;
	}

	for(int i = 0;i<degree.size();i++){
		nodes.insert(i);
		// if(degree[i]>0) 
			pq.push({degree[i],i});
	}

	while(!pq.empty()){

		bool flag = false;
		int deg = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(nodes.find(node) == nodes.end()) continue;
		for(int i = 0;i<tree[node].size();i++){
			if(nodes.find(tree[node][i]) == nodes.end()){
				flag = true;
				break;
			}
		} 

		if(flag) continue;

		cout<<node<<" "<<deg<<"\n";
		nodes.erase(node);
		ans++;
		for(int i = 0;i<tree[node].size();i++) nodes.erase(tree[node][i]);
	}
	
	cout<<ans<<"\n";

	return 0;
}
