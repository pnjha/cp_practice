// https://online.codingblocks.com/player/33819/content/13653/5265

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
unordered_map<int,int> ump;  //pond_id size

int dfs(int i,int j, int color){

	int cnt = 1;

	graph[i][j] = color;

	if(i-1>=0&&graph[i-1][j]==1){
		cnt += dfs(i-1,j,color);
	}
	if(j-1>=0&&graph[i][j-1]==1){
		cnt += dfs(i,j-1,color);	
	}
	if(i+1<graph.size()&&graph[i+1][j]==1){
		cnt += dfs(i+1,j,color);
	}
	if(j+1<graph[i].size()&&graph[i][j+1]==1){
		cnt += dfs(i,j+1,color);
	}

	return cnt;
}

int main(){

	int n,m;
	cin>>n>>m;

	graph.clear();
	graph.resize(n,vector<int>(m,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>graph[i][j];
		}
	}

	int id = 2,cnt = 0;

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(graph[i][j]==1){
				cnt = dfs(i,j,id);
				ump[id] = cnt;
				cnt = 0;
				id++;
			}
		}
	}

	int ans = 0,temp = 0;
	unordered_map<int,int> gid;

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(graph[i][j]==0){
				if(i-1>=0&&graph[i-1][j]!=0){
					gid[graph[i-1][j]]=ump[graph[i-1][j]];
				}
				if(j-1>=0&&graph[i][j-1]!=0){
					gid[graph[i][j-1]]=ump[graph[i][j-1]];
				}
				if(i+1<graph.size()&&graph[i+1][j]!=0){
					gid[graph[i+1][j]]=ump[graph[i+1][j]];
				}
				if(j+1<graph[i].size()&&graph[i][j+1]!=0){
					gid[graph[i][j+1]]=ump[graph[i][j+1]];
				}
			}
			for(auto a:gid){
				temp += a.second;
			}
			if(temp>ans)
				ans = temp;
			temp = 0;
			gid.clear();
		}
	}

	cout<<ans+1<<"\n";

	return 0;
}
