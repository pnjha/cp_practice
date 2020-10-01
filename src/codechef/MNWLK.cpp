// https://www.codechef.com/COOK111B/problems/MNWLK
#include <bits/stdc++.h>
#define ll long long int 

using namespace std; 

vector<ll> cycle;
vector<bool> visited;
map<pair<ll,ll>,ll> mp;
vector<vector<ll>>graph;

bool dfs(ll curr, ll root, ll parent,ll n){
	if(visited[curr]){
		if(curr == root || (curr>=n && curr == root+n)){
			cycle.push_back(root);
			return true;
		}
		return false; 
	}
	// cout<<curr<<" "<<root<<" "<<n<<"\n";
	visited[curr] = true;
	cycle.push_back(curr);
	for(int i = 0;i<graph[curr].size();i++){
		// cout<<"graph[curr][i]: "<<graph[curr][i]<<"\n";
		if(graph[curr][i]!=parent && dfs(graph[curr][i],root,curr,n)) return true;
	}
	visited[curr] = false;
	cycle.pop_back();
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	ll t,n,m,a,b,c=0; 

	cin>>t;
	while(t--){
		
		cin>>n>>m;
		mp.clear();
		graph.clear(),graph.resize(2*n);
		visited.clear(), visited.resize(2*n);

		for(int i = 0;i<m;i++){
			cin>>a>>b;
			a--,b--;
			mp[{a,b+n}] = i+1,mp[{b+n,a}] = i+1;
			graph[a].push_back(b+n);
			graph[b+n].push_back(a);
		}
		
		bool flag = false;

		for(int i = 0;i<n;i++){
			if(graph[i].size()>0){
				cycle.clear();
				// cout<<i<<"\n";
				if(dfs(i,i,i,n)){
					// cout<<"cycle\n";
					// for(int j = 0;j<cycle.size();j++) cout<<cycle[j]<<" ";
					// cout<<"\n";
					if(cycle.size()%2==1) {flag = true; break;}
				}
			}
		}

		if(flag){
			cout<<":)\n";
			for(int i = 1;i<cycle.size();i++){
				a = cycle[i-1], b = cycle[i];
				cout<<mp[{a,b}]<<" ";
			}cout<<"\n";
		}
		else cout<<":(\n"; 
	}
	return 0;
} 
