#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;

int min_path_length(int c,int ax,int ay){

	int coins = grid[0][0]==2?0:1, len=0, x,y;
	//path_len, coins, x,y
	queue<pair<int,pair<int,pair<int,int>>>> q;
	q.push({0,{coins,{0,0}}});	

	while(!q.empty()){
		
		len = q.top().first;
		coins = q.top().second.first;
		x = q.top().second.second.first;
		y = q.top().second.second.second;
		q.pop();

		if(x == ax && y == ay && coins == c) return len;
		
		visited[x][y] = 1;
		
		if(x-1>=0&&grid[x-1][y]!=1&&visited[x-1][y]!=1) 
			q.push(len+1,{grid[x-1][y]==2?coins+1:coins,{x-1,y}});
		
		if(y-1>=0&&grid[x][y-1]!=1&&visited[x][y-1]!=1) 
			q.push(len+1,{grid[x][y-1]==2?coins+1:coins,{x,y-1}});
		
		if(x+1<grid.size()&&grid[x+1][y]!=1&&visited[x+1][y]!=1) 
			q.push(len+1,{grid[x+1][y]==2?coins+1:coins,{x+1,y}});
		
		if(y+1<grid[x].size()&&grid[x][y+1]!=1&&visited[x][y+1]!=1) 
			q.push(len+1,{grid[x][y+1]==2?coins+1:coins,{x,y+1}});
	}

	return -1;
}

int main(){

	int rows,cols,coins=0,ax,ay;
	cin>>rows>>cols;
	grid.clear();
	grid.resize(rows,vector<int>(cols,0));
	visited.clear();
	visited.resize(rows,vector<int>(cols,0));

	for(int i = 0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>grid[i][j];
			if(grid[i][j]==2) coins++;
		}
	}

	cin>>ax>>ay;
	cout<<min_path_length(coins,ax,ay)<<"\n";
	return 0;
}
