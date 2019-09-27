// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/practice-problems/algorithm/logo-hunting-2d4068ca/
#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> graph;
vector<char> letter = {'F','O','P','N'};
int holes = 0;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

void dfs_background(int row,int col){

	// cout<<row<<" "<<col<<"\n";

	if(row<0||col<0||row>=graph.size()||col>=graph[row].size()||graph[row][col]=='u'||graph[row][col]=='1')
		return;

	if(graph[row][col] == '.'){
		graph[row][col] = 'u';
	}

	for(int i = 0;i<dx.size();i++){
		dfs_background(row+dx[i],col+dy[i]);
	}
}

void dfs(int row,int col){

	if(row<0||col<0||row>=graph.size()||col>=graph[row].size()||graph[row][col]=='u'||graph[row][col]=='X'||graph[row][col]=='Y')
		return;	

	// for(int i = 0;i<graph.size();i++){
	// 	for(int j = 0;j<graph[i].size();j++){
	// 		cout<<graph[i][j];
	// 	}cout<<"\n";
	// }

	// cout<<row<<" "<<col<<" "<< graph[row][col]<<"\n";

	bool flag = true;

	if(graph[row][col] == '.'){
		
		for(int i = 0;i<dx.size();i++){
			if(row+dx[i]>=0&&col+dy[i]>=0&&row+dx[i]<graph.size()&&col+dy[i]<graph[row].size()){
				if(graph[row+dx[i]][col+dy[i]]=='X'){
					flag = false;
					break;
				}
			}
		}

		if(flag)
			holes++;
		flag = true;

		graph[row][col] = 'X';
		
	}else if(graph[row][col] == '1'){
		graph[row][col] = 'Y';
	}

	for(int i = 0;i<dx.size();i++){
		dfs(row+dx[i],col+dy[i]);
	}
}

int main(){

	freopen("input.txt","r",stdin);

	int n,m;
	cin>>n>>m;

	graph.clear();
	graph.resize(n,vector<char>(m));


	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>graph[i][j];
		}
	}

	dfs_background(0,0);

	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<m;j++){
	// 		cout<<graph[i][j];
	// 	}cout<<"\n";
	// }

	string res = "";
	bool flag = false;

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(graph[i][j]=='1'){
				flag = true;
				holes = 0;
				dfs(i,j);
				// cout<<"holes: "<<holes<<"\n";
				res += letter[holes];
			}
		}
	}



	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<m;j++){
	// 		cout<<graph[i][j];
	// 	}cout<<"\n";
	// }
	if(!flag)
		cout<<"N\n";
	else{
		sort(res.begin(),res.end());
		cout<<res<<"\n";
	}

	return 0;
}
