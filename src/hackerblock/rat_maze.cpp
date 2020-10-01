#include<bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;

bool dfs(vector<string>& maze, int row, int col){

	if(row==maze.size()-1&&col==maze[0].length()-1){
		visited[row][col] = true;		
		return true;
	}

	if(row<0||col<0||row>=maze.size()||col>=maze[row].length()||visited[row][col] == true||maze[row][col]=='X')
		return false;

	visited[row][col] = true;

	if(dfs(maze,row,col+1))
		return true;

	if(dfs(maze,row+1,col))
		return true;	

	visited[row][col] = false;
	return false;
}

int main(){

	freopen("input.txt","r",stdin);

	bool flag = false;
	int n,m,sum=0;
	cin>>n>>m;

	vector<string> maze(n);

	visited.clear();
	visited.resize(n,vector<bool>(m,false));

	for(int i = 0;i<n;i++)
		cin>>maze[i];

	if(dfs(maze,0,0)){

		for(int i = 0;i<visited.size();i++){
			for(int j = 0;j<visited[i].size();j++){
				cout<<visited[i][j]<<" ";
			}
			cout<<"\n";
		}
	}else{
		cout<<"-1\n";
	}

	return 0;
}