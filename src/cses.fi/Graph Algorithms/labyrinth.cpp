#include<bits/stdc++.h>

using namespace std;

int starti,endi,startj,endj;

vector<char> ans;

int min_len = INT_MAX;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};
vector<char> m_c = {'U','D','L','R'};

void dfs(vector<vector<char>>& grid,int row,int col,vector<char>& temp){

	if(row == endi && col == endj){
		if(temp.size()<min_len){
			ans = temp;
			min_len = temp.size();
		}
		return;
	}

	int x,y;

	for(int i = 0;i<dx.size();i++){

		x = row+dx[i];
		y = col+dy[i];

		if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&(grid[x][y]=='.'||grid[x][y]=='B')){

			grid[x][y] = '#';
			temp.push_back(m_c[i]);
			dfs(grid,x,y,temp);
			grid[x][y] = '.';
			temp.pop_back();
		}	
	}
}

string bfs(vector<vector<char>>& grid){

	queue<pair<pair<int,int>,string>> q;
	pair<pair<int,int>,string> parent,child;

	q.push({{starti,startj},""});

	int x,y;
	string path = "";
	bool flag = false;

	while(!q.empty()){

		parent = q.front();
		q.pop();

		for(int i = 0;i<dx.size();i++){

			x = parent.first.first+dx[i];
			y = parent.first.second+dy[i];

			if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()){
				
				if(grid[x][y]=='.'){

					q.push({{x,y},parent.second+m_c[i]});
				}
				else if(grid[x][y]=='B'){
					return (parent.second+m_c[i]);
				}
			}
		}
	}
	return "";
}

int main(){

	int n,m;
	cin>>n>>m;

	ans.clear();

	vector<vector<char>> grid(n,vector<char>(m));

	for(int i = 0;i<n;i++){

		for(int j = 0;j<m;j++){

			cin>>grid[i][j];
			if(grid[i][j] == 'A'){
				starti = i;
				startj = j;
			}else if(grid[i][j] == 'B'){
				endi = i;
				endj = j;
			}
		}

	}

	// vector<char> temp;

	// dfs(grid,starti,startj,temp);

	// if(ans.size()>0)
	// 	cout<<"YES\n";
	// else{
	// 	cout<<"NO\n";
	// 	return 0;
	// }
	// cout<<ans.size()<<" \n";
	// for(int i = 0;i<ans.size();i++){
	// 	cout<<ans[i];
	// }
	// cout<<"\n";

	string s = bfs(grid);

	if(s.length()==0){

		cout<<"NO\n";
	}else{

		cout<<"YES\n";
		cout<<s.length()<<"\n";
		cout<<s<<"\n";
	}

	return 0;
}