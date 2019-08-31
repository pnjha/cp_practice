#include<bits/stdc++.h>

using namespace std;

int starti=-1,endi=-1,startj=-1,endj=-1;

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

vector<char> bidirectional_bfs(vector<vector<char>>& grid){

	vector<vector<pair<int, vector<char>>>> visited(grid.size(),vector<pair<int, vector<char>>>(grid[0].size())); //1 for start and 2 for end 0 for unvisited.
	vector<pair<int,int>> start, end, curr, temp;
	bool set_flag = true, flag = false; //true for start and false for end.

	vector<char> path,a1,a2;
	int x,y,nx,ny;

	for(int i = 0;i<visited.size();i++){
		for(int j = 0;j<visited[i].size();j++){
			visited[i][j].first = 0;
		}
	}

	start.push_back({starti,startj});
	end.push_back({endi,endj});

	visited[starti][startj] = {1,{}};
	visited[endi][endj] = {2,{}};

	while(start.size()!=0 && end.size()!=0){
		
		// cout<<start.size()<<" "<<end.size()<<"\n";

		temp.clear();

		if(start.size()<=end.size()){
			set_flag = true;
			curr = start;
			start.clear();
		}else{
			set_flag = false;
			curr = end;
			end.clear();
		}

		for(int i = 0;i<curr.size();i++){

			x = curr[i].first;
			y = curr[i].second;
			path = visited[x][y].second;

			for(int j = 0;j<dx.size();j++){

				nx = x + dx[j], ny = y + dy[j];

				path.push_back(m_c[j]);
				
				if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[nx].size()&&grid[nx][ny]!='#'){
					
					if(visited[nx][ny].first == 1 && !set_flag){
						// cout<<"one\n";
						a1 = visited[nx][ny].second;
						a2 = path;
						flag = true;
						break;
					}else if(visited[nx][ny].first == 2 && set_flag){
						// cout<<"two\n";
						a2 = visited[nx][ny].second;
						a1 = path;
						flag = true;
						break;
					}else if(visited[nx][ny].first==0){

						temp.push_back({nx,ny});
						visited[nx][ny] = {set_flag?1:2,path};
					}
				}
				path.pop_back();
			}

			if(flag)
				break;
		}

		if(flag)
			break;

		curr.clear();

		if(set_flag){
			start = temp;
		}else{
			end = temp;
		}
	}

	// if(a1.size()==0||a2.size()==0)
	// 	return {};

	path.clear();

	for(int i = 0;i<a1.size();i++){
		// cout<<a1[i]<<" ";
		path.push_back(a1[i]);
	}
	// cout<<"\n";
	for(int i = a2.size()-1;i>=0;i--){
		// cout<<a2[i]<<" ";
		if(a2[i] == 'U'){
			path.push_back('D');		
		}else if(a2[i] == 'R'){
			path.push_back('L');
		}else if(a2[i] == 'D'){
			path.push_back('U');
		}else if(a2[i] == 'L'){
			path.push_back('R');
		}
	}
	// cout<<"\n";
	return path;
}



int main(){

	int clk = clock();

	// freopen("input.txt","r",stdin);
	// freopen("ouput.txt","w",stdout);

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

	if(endi==-1 || starti==-1){
		cout<<"NO\n";
		return 0;
	}

	// {
	// 	vector<char> temp;

	// 	dfs(grid,starti,startj,temp);

	// 	if(ans.size()>0)
	// 		cout<<"YES\n";
	// 	else{
	// 		cout<<"NO\n";
	// 		return 0;
	// 	}
	// 	cout<<ans.size()<<" \n";
	// 	for(int i = 0;i<ans.size();i++){
	// 		cout<<ans[i];
	// 	}
	// 	cout<<"\n";

	// 	string s = bfs(grid);

	// 	if(s.length()==0){

	// 		cout<<"NO\n";
	// 	}else{

	// 		cout<<"YES\n";
	// 		cout<<s.length()<<"\n";
	// 		cout<<s<<"\n";
	// 	}
	// }

	// vector<char> s = bfs(grid);

	vector<char> s = bidirectional_bfs(grid);

	if(s.size()==0){
		cout<<"NO\n";
	
	}else{

		cout<<"YES\n";
		cout<<s.size()<<"\n";
		for(int i = 0;i<s.size();i++)
			cout<<s[i];
		cout<<"\n";

	}

	// cout<<"Clock time: "<<clock() - clk<<"\n";

	return 0;
}