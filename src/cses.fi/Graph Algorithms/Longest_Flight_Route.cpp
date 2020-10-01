// https://cses.fi/problemset/task/1680
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

vector<vector<int>> graph;
vector<int> route;

void bfs(int& n, int& m){

	queue<pair<int,vector<int>>> q;
	q.push({1,{}});

	bool flag = false;
	ll msf = 0,node;
	vector<int> path; 

	while(!q.empty()){

		node = q.front().first;
		path = q.front().second;
		path.push_back(node);

		q.pop();

		if(node == n){
			flag = true;
			if(path.size()>route.size()){
				route = path;
			}
			continue;
		}

		if(node!=n){
			int l = graph[node].size();
			for(int i = 0;i<l;i++){
				q.push({graph[node][i],path});
			}
		}
	}

	// route.push_back(n);
}

int main(){

	// int clk = clock();

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n,m,a,b;

	cin>>n>>m;

	graph.clear();
	graph.resize(n+1);

	route.clear();

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		if((a!=b) && (graph[a].size()==0 || graph[a].back()!=b)){	
			graph[a].push_back(b);
		}
	}

	bool flag = true;

	for(int i = 1;i<=n;i++){
		if(i!=n && graph[i].size()==1){
			if(graph[i][0]!=i+1){
				flag = false;
				break;
			}
		}else if(i!=n){
			flag = false;
			break;
		}
	}

	if(!flag){

		// cout<<"here\n";

		bfs(n,m);

		if(route.size()!=0){
			cout<<route.size()<<"\n";

			for(int i = 0;i<route.size();i++){
				if(i==route.size()-1){
					cout<<route[i];
				}else{
					cout<<route[i]<<" ";
				}
			}

		}else{
			cout<<"IMPOSSIBLE\n";
		}
	
	}else{
		cout<<n<<"\n";
		for(int i = 1;i<=n;i++){
			cout<<i<<" ";
		}		
	}

	// cout<<"Clock time: "<<clock() - clk<<"\n";

	return 0;
}
