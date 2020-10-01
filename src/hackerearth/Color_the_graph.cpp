// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/color-the-graph/description/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> color; //-1 not colored 0 red 1 blue 3 explored

bool dfs(int index,int colour, int& visitcnt, int& cnt){

	for(int i = 0;i<graph[index].size();i++){
		if(color[graph[index][i]] == colour)
			return false;
	}

	visitcnt++;

	color[index] = colour;
	if(colour == 0)
		cnt++;

	for(int i = 0;i<graph[index].size();i++){

		if(color[graph[index][i]]==-1){		

			if(!dfs(graph[index][i],1-colour,visitcnt,cnt)){

				return false;
			}
		}
	}

	color[index] = 3;
	return true;
}

int main(){

	freopen("input.txt","r",stdin);

	int t,n,m,a,b;
	bool flag = true;
	cin>>t;

	while(t--){

		cin>>n>>m;

		graph.clear();
		graph.resize(n+1);

		color.clear();
		color.resize(n+1,-1);

		for(int i = 0;i<m;i++){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		int cnt = 0,visitcnt = 0,ans = 0;

		for(int i = 1;i<color.size();i++){

			if(color[i] == -1){

				flag = dfs(i,0,visitcnt,cnt);
				
				if(flag){

					ans += max(visitcnt-cnt,cnt);
				
				}else{
				
					break;	
				}
			}
			visitcnt = 0;
			cnt = 0;
		}

		if(flag){
			cout<<ans<<"\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}
