#include<bits/stdc++.h>
#define SIZE 8
using namespace std;

vector<vector<int>> ans; 

static vector<int> dx = {1,1,2,2,-1,-1,-2,-2};
static vector<int> dy = {2,-2,1,-1,2,-2,1,-1};

bool cmp(pair<int,pair<int,int>>p1, pair<int,pair<int,int>>p2){

	if(p1.first<p2.first)
		return false;
	return true;
}

int get_visited_neighbours(int row, int col){

	int cnt = 0;

	for(int i = 0;i<dx.size();i++){

		if(row+dx[i]>=0&&col+dy[i]>=0&&row+dx[i]<SIZE&&col+dy[i]<SIZE&&ans[row+dx[i]][col+dy[i]]==-1){

			cnt++;

		}

	}

	return cnt;
}

bool dfs(int row,int col,int steps){

	// cout<<row<<" "<<col<<" "<<steps<<"\n";

	if(row<0||col<0||row>=SIZE||col>=SIZE||steps>65||ans[row][col]!=-1)
		return false;

	if(steps == 64){
		ans[row][col] = 64;
		return true;
	}

	ans[row][col] = steps;

	vector<pair<int,pair<int,int>>> points;

	for(int i = 0;i<dx.size();i++){

		if(row+dx[i]>=0&&col+dy[i]>=0&&row+dx[i]<SIZE&&col+dy[i]<SIZE&&ans[row+dx[i]][col+dy[i]]==-1)
			points.push_back({get_visited_neighbours(row+dx[i],col+dy[i]),{row+dx[i],col+dy[i]}});

	}

	sort(points.begin(),points.end());

	for(int i = 0;i<points.size();i++){

		if(dfs(points[i].second.first,points[i].second.second,steps+1))
			return true;

	}


	ans[row][col] = -1;
	return false;
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	ans.clear();
	ans.resize(SIZE,vector<int>(SIZE,-1));

	int steps = 1;

	int row,col;
	cin>>row>>col;

	row--;
	col--;

	dfs(col,row,steps);

	for(int i = 0;i<SIZE;i++){
		for(int j = 0;j<SIZE;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
