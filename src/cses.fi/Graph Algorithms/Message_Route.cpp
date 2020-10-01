// https://cses.fi/problemset/task/1667/
/*
	Maintaining vector of string is more costly than just string 
*/
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void _bfs(){

	vector<string> path;
	bool flag = false;

	queue<pair<int,vector<string>>> q;
	q.push({1,{"1"}});

	pair<int,vector<string>> p;
	visited[1] = true;

	while(!q.empty()){

		p = q.front();
		q.pop();

		for(int i = 0;i<graph[p.first].size();i++){

			if(graph[p.first][i] == visited.size()-1){
				path = p.second;
				path.push_back(to_string(graph[p.first][i]));
				flag = true;
				break;
			}

			if(!visited[graph[p.first][i]]){
				path = p.second;
				path.push_back(to_string(graph[p.first][i]));
				q.push({graph[p.first][i],path});
				visited[graph[p.first][i]] = true;
			}

		}

		if(flag)
			break;
	}

	if(path.size()==0){
		cout<<"IMPOSSIBLE\n";
	}else{
		cout<<path.size()<<"\n";
		for(int i = 0;i<path.size();i++){
			cout<<path[i]<<" ";
		}cout<<"\n";
	}
}

void bfs(){

	string path = "";
	long long len = 0;
	bool flag = false;

	queue<pair<int,pair<int,string>>> q;
	q.push({1,{1,"1"}});

	pair<int,pair<int,string>> p;
	visited[1] = true;

	while(!q.empty()){

		p = q.front();
		q.pop();

		for(int i = 0;i<graph[p.first].size();i++){

			if(graph[p.first][i] == visited.size()-1){
				path = p.second.second +" "+ to_string(graph[p.first][i]);
				len = p.second.first+1;
				flag = true;
				break;
			}

			if(!visited[graph[p.first][i]]){
				path = p.second.second +" "+ to_string(graph[p.first][i]);
				len = len = p.second.first+1;
				q.push({graph[p.first][i],{len,path}});
				visited[graph[p.first][i]] = true;
			}

		}

		if(flag)
			break;
	}

	if(!flag){
		cout<<"IMPOSSIBLE\n";
	}else{
		cout<<len<<"\n";
		cout<<path<<"\n";
	}
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m,a,b;
	cin>>n>>m;

	visited.clear();
	visited.resize(n+1);

	graph.clear();
	graph.resize(n+1);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}	

	bfs();

	return 0;
}
