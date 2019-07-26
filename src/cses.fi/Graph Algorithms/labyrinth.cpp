#include<bits/stdc++.h>

using namespace std;

int starti,endi,startj,endj;

vector<char> ans;

int min_len = INT_MAX;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
vector<char> m_c = {'D','U','R','L'};

vector<vector<bool>> visited;

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

bool cmp(pair<double,pair<pair<int,int>,vector<char>>>p1, pair<double,pair<pair<int,int>,vector<char>>>p2){

	if(p1.first<p2.first)
		return false;
	return true;
}

vector<char> bfs(vector<vector<char>>& grid){

	queue<pair<pair<int,int>,vector<char>>> q;
	pair<pair<int,int>,vector<char>> parent,child;
	vector<pair<double,pair<pair<int,int>,vector<char>>>> children;
	vector<char> ch;

	q.push({{starti,startj},{}});

	visited[starti][startj] = true;

	double dist = 0.0;
	int x,y;
	bool flag = false;

	while(!q.empty()){

		parent = q.front();
		q.pop();

		children.clear();
		children = {{INT_MAX,{{0,0},{}}},{INT_MAX,{{0,0},{}}},{INT_MAX,{{0,0},{}}},{INT_MAX,{{0,0},{}}}};

		for(int i = 0;i<dx.size();i++){

			x = parent.first.first+dx[i];
			y = parent.first.second+dy[i];

			if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]=='#')
				continue;


			if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&!visited[x][y]){


				visited[x][y] = true;
				if(grid[x][y]=='.'){
		
					ch.clear();
					ch = parent.second;
					ch.push_back(m_c[i]);

					dist = (endi - x) + (endj - y);
					children[i] = {dist,{{x,y},ch}};
					
					// q.push({{x,y},parent.second.push_back(m_c[i])});
				}
				else if(grid[x][y]=='B'){
					ch = parent.second;
					ch.push_back(m_c[i]);
					return ch;
					// return parent.second.push_back(m_c[i]);
				}
			}
		}

		sort(children.begin(),children.end(),cmp);

		for(int i = 0;i<children.size();i++){
			if(children[i].first!=INT_MAX)
				q.push(children[i].second);
		}
	}
	return {};
}

int main(){

	int clk = clock();

	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	ans.clear();
	visited.clear();
	visited.resize(n,vector<bool>(m));

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

	// string s = bfs(grid);

	// if(s.length()==0){

	// 	cout<<"NO\n";
	// }else{

	// 	cout<<"YES\n";
	// 	cout<<s.length()<<"\n";
	// 	cout<<s<<"\n";
	// }

	vector<char> s = bfs(grid);

	if(s.size()==0){
		cout<<"NO\n";
	
	}else{

		cout<<"YES\n";
		cout<<s.size()<<"\n";
		for(int i = 0;i<s.size();i++)
			cout<<s[i];
		cout<<"\n";

	}

	cout<<clock() - clk<<"\n";

	return 0;
}