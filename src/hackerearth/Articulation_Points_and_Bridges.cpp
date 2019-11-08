// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited_time;
vector<int> articultaion_points;
vector<pair<int,int>> bridges;
vector<int> low_time;

int root;

bool cmp(pair<int,int>&p1,pair<int,int>&p2){
	if(p1.first<p2.first){
		return true;
	}else{
		if(p1.second<p2.second){
			return true;
		}
	}
	return false;
}
{
	// void dfs(int index, int time, int parent){

	// 	visited_time[index] = time;
	// 	low_time[index] = time;
	// 	int children = 0;

	// 	for(int i = 0;i<graph[index].size();i++){
				
	// 		if(graph[index][i] == parent) continue;

	// 		if(visited_time[graph[index][i]]!=-1){
	            
	//             low_time[index] = min(low_time[index], visited_time[graph[index][i]]);
	            
	            
	// 		}else{
			    
	// 			dfs(graph[index][i],time+1, index);	
				
	// 			low_time[index] = min(low_time[index], low_time[graph[index][i]]);

	// 			if(low_time[graph[index][i]]>visited_time[index]){				
	// 				bridges.push_back({min(index,graph[index][i]),max(index,graph[index][i])});
	// 			}
	    				
	// 			if(low_time[graph[index][i]]>=visited_time[index] && root!=index){
	// 				articultaion_points.push_back(index);	
	// 			}
				
	// 			children++;
	// 		}
	// 	}
		
	// 	if(index == root && children>1){
	// 	    articultaion_points.push_back(index);
	// 	}
	// }
}

void dfs(int index, int time, int parent){

	visited_time[index] = time;
	// low_time[index] = time;
	int children = 0;

	for(int i = 0;i<graph[index].size();i++){
			
		if(graph[index][i] == parent) continue;

		if(visited_time[graph[index][i]]!=-1){
            
            visited_time[index] = min(visited_time[index], visited_time[graph[index][i]]);
            
            
		}else{
		    
			dfs(graph[index][i],time+1, index);	
			
			if(visited_time[graph[index][i]]>visited_time[index]){				
				bridges.push_back({min(index,graph[index][i]),max(index,graph[index][i])});
			}
    				
			if(visited_time[graph[index][i]]>=visited_time[index] && root!=index){
				articultaion_points.push_back(index);	
			}

			visited_time[index] = min(visited_time[index], visited_time[graph[index][i]]);
			
			children++;
		}
	}
	
	if(index == root && children>1){
	    articultaion_points.push_back(index);
	}
}

int main(){

	// freopen("input.txt","r",stdin);

	int n,m,a,b;
	cin>>n>>m;

	bridges.clear();
	articultaion_points.clear();
	
	visited_time.clear();
	visited_time.resize(n,-1);
	
	low_time.clear();
    low_time.resize(n,INT_MAX);
    
	graph.clear();
	graph.resize(n);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for(int i = 0;i<n;i++){
		if(visited_time[i]==-1){
			root = i;
			dfs(i,0,0);
		}
	}

	// for(int i = 0;i<visited_time.size();i++)
	// 	cout<<visited_time[i]<<" ";
	// cout<<"\n";

	sort(bridges.begin(),bridges.end(),cmp);
	sort(articultaion_points.begin(),articultaion_points.end());

	cout<<articultaion_points.size()<<"\n";
	for(int i = 0;i<articultaion_points.size();i++)
		cout<<articultaion_points[i]<<" ";
	cout<<"\n";

	cout<<bridges.size()<<"\n";
	for(int i = 0;i<bridges.size();i++)
		cout<<bridges[i].first<<" "<<bridges[i].second<<"\n";

	return 0;
}
