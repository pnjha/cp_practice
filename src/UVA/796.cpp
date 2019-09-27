//Find all bridges in a graph 
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<pair<int,int>> bridges;
vector<int> visited_time;

void dfs(int node, int parent, int time){

	// cout<<"Entering: "<<node<<" "<<time<<"\n";

	if(visited_time[node]!=-1){
		return;
	}

	visited_time[node] = time;

	for(int i = 0;i<graph[node].size();i++){

		if(graph[node][i]==parent)
			continue;

		if(visited_time[graph[node][i]]==-1){
			dfs(graph[node][i], node, time+1);
			if(visited_time[graph[node][i]]>visited_time[node]){				
				bridges.push_back({min(node,graph[node][i]),max(node,graph[node][i])});
			}
		}
	}	


	for(int i = 0;i<graph[node].size();i++){
		if(visited_time[graph[node][i]]!=-1 && graph[node][i]!=parent){
			visited_time[node] = min(visited_time[node], visited_time[graph[node][i]]);	
		}
	}

	// cout<<"Exiting: "<<node<<" "<<visited_time[node]<<"\n";
}

void find_bridges(){

	visited_time.clear();
	visited_time.resize(graph.size(),-1);

	for(int i = 0;i<visited_time.size();i++){
		if(visited_time[i] == -1){
			dfs(i,i,1);
		}
	}

	// for(int i = 0;i<graph.size();i++){
	// 	cout<<visited_time[i]<<" ";
	// }cout<<"\n";
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	bool flag = true;
	int n,a,b,m;
	string s,num_str;

	while(cin>>n){

		// if(!flag)
		// 	cout<<"\n";

		// flag = false;

		if(n == 0){
			cout<<"0 critical links\n\n";
			continue;
		}

		graph.clear();
		graph.resize(n);

		bridges.clear();

		for(int k = 0;k<n;k++){

			cin>>a>>s;
			num_str = "";
			for(int i = 0;i<s.length();i++){
				if(s[i]!='(' && s[i]!=')')
					num_str += s[i];
			}

			m = stoi(num_str);

			for(int i = 0;i<m;i++){
				cin>>b;
				graph[a].push_back(b);
			}
		}

		// for(int i = 0;i<n;i++){
		// 	cout<<i<<" : ";
		// 	for(int j = 0;j<graph[i].size();j++){
		// 		cout<<graph[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }

		find_bridges();

		cout<<bridges.size()<<" critical links\n";
		
		sort(bridges.begin(),bridges.end());

		for(int i = 0;i<bridges.size();i++){
			cout<<bridges[i].first<<" - "<<bridges[i].second<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}
