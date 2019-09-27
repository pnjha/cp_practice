// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=251

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> low_time;
vector<int> visited_time;
map<int,bool> ap;
int root = 0;

void dfs(int node, int parent, int time){

	int children = 0;
	visited_time[node] = low_time[node] = time;

	for(int i = 0;i<graph[node].size();i++){
		if(graph[node][i] == parent) continue;
		if(visited_time[graph[node][i]]!=-1){
			low_time[node] = min(low_time[node], visited_time[graph[node][i]]);
		}else{
			dfs(graph[node][i],node,time+1);
			children++;
			low_time[node] = min(low_time[node], low_time[graph[node][i]]);
			if(low_time[graph[node][i]] >= visited_time[node] && node != root){
				ap[node] = true;
			}
		}
	}
	if(children>1 && node == root)
		ap[node] = true;
}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	char c;
	bool flag = false;
	int n,m,a,b;
	string s,temp="";

	while(cin>>n){
		
		// cout<<n<<"\n";

		if(n == 0){
			// cout<<"Over\n";
			break;
		}

		low_time.clear();
		low_time.resize(n,INT_MAX);

		visited_time.clear();
		visited_time.resize(n,-1);

		graph.clear();
		graph.resize(n);
		
		ap.clear();
		cin.ignore();
		
		for(int i = 0;i<n;i++){

			getline(cin,s);

			// cout<<s<<"\n";

			if(s.length() == 0){
				continue;
			}

			if(s[0] == '0'){
				flag=true;
				break;
			}
			
			b = 0;
			temp="";
			
			while(s[b]!=' '){
				temp+=s[b];
				b++;
			}
			b++;

			m = stoi(temp);
			// cout<<m<<"\n";
			while(b<s.length()){
				temp="";
				while(b<s.length() && s[b]!=' '){
					temp+=s[b];
					b++;
				}
				graph[m-1].push_back(stoi(temp)-1);
				graph[stoi(temp)-1].push_back(m-1);
				b++;
			}
		}

		if(!flag)
			cin.ignore();
		flag = false;
		// for(int i = 0;i<n;i++){
		// 	cout<<i<<": ";
		// 	for(int j = 0;j<graph[i].size();j++){
		// 		cout<<graph[i][j]<<" ";
		// 	}cout<<"\n";
		// }

		for(int i = 0;i<n;i++){
			if(visited_time[i] == -1)
				root = i;
				dfs(i,i,0);
		}

		cout<<ap.size()<<"\n";
	}

	return 0;
}


/*
Sample Input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
Sample Output
1
2
*/