#include<bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;

void dfs(vector<vector<char>>& building,int row, int col){

	if(row<0||col<0||row>=building.size()||col>=building[row].size()||visited[row][col]||building[row][col]=='#')
		return;

	visited[row][col] = true;

	dfs(building,row-1,col);
	dfs(building,row,col-1);
	dfs(building,row+1,col);
	dfs(building,row,col+1);
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	vector<vector<char>>building(n,vector<char>(m));
	visited.clear();
	visited.resize(n,vector<bool>(m,false));

	int cnt = 0;

	for(int i = 0;i<n;i++){

		for(int j = 0;j<m;j++){
			cin>>building[i][j];
		}
	}

	for(int i = 0;i<n;i++){

		for(int j = 0;j<m;j++){

			if(building[i][j]!='#'&&!visited[i][j]){

				dfs(building,i,j);
				cnt++;
			}

		}

	}

	cout<<cnt<<"\n";
	return 0;
}
