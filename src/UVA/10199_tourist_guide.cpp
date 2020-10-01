// https://uva.onlinejudge.org/indicies.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1140

#include<bits/stdc++.h>

using namespace std;

map<string,int> indicies;
map<int,string> reverse_index;
vector<vector<int>>graph;
vector<int> visited_time;
vector<int> low_time;
map<int,bool> ap;
int root = 0;

void dfs(int node, int parent, int time){

	visited_time[node] = low_time[node] = time;
	int children = 0;

	for(int i = 0;i<graph[node].size();i++){

		if(graph[node][i] == parent) continue;

		if(visited_time[graph[node][i]]!=-1){
			low_time[node] = min(low_time[node], visited_time[graph[node][i]]);
		}else{
			dfs(graph[node][i],node,time+1);
			children++;
			low_time[node] = min(low_time[node], low_time[graph[node][i]]);
			if(low_time[graph[node][i]] >= visited_time[node] && node!=root){
				ap[node] = true;
			}
		}
	}

	if(node == root && children > 1){
		ap[node] = true;
	}
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n,m,cnt = 0;
	string s,a,b;

	while(true){

		cin>>n;
		if(n == 0)
			break;
		else if(cnt!=0)
			cout<<"\n";

		cnt++;

		indicies.clear();
		reverse_index.clear();

		low_time.clear();
		low_time.resize(n,INT_MAX);

		visited_time.clear();
		visited_time.resize(n,-1);		

		ap.clear();

		graph.clear();
		graph.resize(n);

		for(int i = 0;i<n;i++){
			cin>>s;
			indicies[s] = i;
			reverse_index[i] = s;
		}

		cin>>m;

		for(int i = 0;i<m;i++){
			cin>>a>>b;
			graph[indicies[a]].push_back(indicies[b]);
			graph[indicies[b]].push_back(indicies[a]);
		}

		for(int i = 0;i<n;i++){
			if(visited_time[i]==-1){
				root = i;
				dfs(i,i,0);
			}
		}

		vector<string> ans;

		cout<<"City map #"<<cnt<<": "<<ap.size()<<" camera(s) found\n";
		for(auto a:ap){
			ans.push_back(reverse_index[a.first]);			
		}
		sort(ans.begin(),ans.end());
		for(int i = 0;i<ans.size();i++)
			cout<<ans[i]<<"\n";
	}

	return 0;
}
