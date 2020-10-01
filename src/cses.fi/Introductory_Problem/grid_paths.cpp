// https://cses.fi/problemset/task/1625
// ???????????????????????????????????????????????

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

string moves;
ll ans;
int visited[7][7];
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
string mv = "ULDR";


int dfs(int x, int y, int index, char m){

	if(index == 48){
		return 1;
	}

	if(visited[6][0])
		return 0;

	if(m =='L' && (y == 0 || visited[x][y-1]) && x > 0 && x < 6 && !visited[x-1][y] && !visited[x+1][y]) return 0;
	if(m =='R' && (y == 6 || visited[x][y+1]) && x > 0 && x < 6 && !visited[x-1][y] && !visited[x+1][y]) return 0;
	if(m =='U' && (x == 0 || visited[x-1][y]) && y > 0 && y < 6 && !visited[x][y-1] && !visited[x][y+1]) return 0;
	if(m =='D' && (x == 6 || visited[x+1][y]) && y > 0 && y < 6 && !visited[x][y-1] && !visited[x][y+1]) return 0;

	int k = 0;

	if(moves[index] == '?'){

		for(int i = 0;i<dx.size();i++){

			int yy = y+dy[i];
			int xx = x+dx[i];

			if(xx<7 && xx>=0 && yy<7 && yy>=0 && !visited[xx][yy]){

				visited[xx][yy] = true;
				k += dfs(xx,yy,index+1,mv[i]);
				visited[xx][yy] = false;
			}
		}

		return k;
	}else{

		int yy;
		int xx;

		if(moves[index]=='L'){

			yy = y-1;
			xx = x;

			if(yy>=0 && !visited[xx][yy]){
				
				visited[xx][yy] = true;
				k = dfs(xx,yy,index+1,'L');
				visited[xx][yy] = false;
			}
		}
		else if(moves[index]=='R'){

			yy = y+1;
			xx = x;
			
			if(yy<7 && !visited[xx][yy]){
				visited[xx][yy] = true;
				k = dfs(xx,yy,index+1,'R');
				visited[xx][yy] = false;
			}	
		} 
		else if(moves[index]=='U'){
			
			yy = y;
			xx = x-1;

			if(xx>=0 && !visited[xx][yy]){
				visited[xx][yy] = true;
				k = dfs(xx,yy,index+1,'U');
				visited[xx][yy] = false;
			}
		}
		else if(moves[index]=='D'){
		
			yy = y;
			xx = x+1;

			if(xx<7 && !visited[xx][yy]){
				visited[xx][yy] = true;
				k = dfs(xx,yy,index+1,'D');
				visited[xx][yy] = false;
			}	
		}
	}
	return k;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>moves;

	memset(visited,false,sizeof(visited));

	visited[0][0] = true;

	ans = 0;

	ans = dfs(0,0,0,0);

	cout<<ans<<"\n";

	return 0;
}


/*
bool trap(int i, int j){
	int x=0,y=0;
	if (i-1>=0 && vis[i-1][j]==0) y++;
	if (i+1<7 && vis[i+1][j]==0) y++;
	if (j-1>=0 && vis[i][j-1]==0) x++;
	if (j+1<7 && vis[i][j+1]==0) x++;
	if ((x==0 && y==2) || (x==2 && y==0)) return 1;
	return 0;
}
*/