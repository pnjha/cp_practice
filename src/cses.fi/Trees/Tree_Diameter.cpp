// https://cses.fi/problemset/task/1131

// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
#define ll long long int
using namespace std;

vector<vector<ll>> graph;
vector<bool> visited;
// vector<ll> node_ans;
// vector<ll> height;
ll ans;

ll diameter_tree(ll node){

	visited[node] = true;

	ll first_max=0,second_max=0,temp=0;

	for(int i = 0;i<graph[node].size();i++){

		if(!visited[graph[node][i]]){

			temp = diameter_tree(graph[node][i]);		

			if(temp>first_max){
				second_max = first_max;
				first_max = temp;
			}else if(temp>second_max){
				second_max =  temp;
			}
		}
	}

	if(ans<first_max+second_max+1)
		ans=(first_max+second_max+1);

	// ans = max(ans, first_max+second_max+1);

	// height[node] = max(first_max,second_max)+1;
	// node_ans[node] = ans;

	ll height = first_max;

	if(first_max<=second_max)
		height = second_max;

	return height+1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,a,b;
	cin>>n;

	// graph.clear();
	graph.resize(n);

	// node_ans.clear();
	// node_ans.resize(n,-1);

	// height.clear();
	// height.resize(n,0);	

	// visited.clear();
	visited.resize(n,false);	

	ans = 0;

	for(int i = 0;i<n-1;i++){
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	diameter_tree(0);

	// for(int i = 0;i<n;i++)
	// 	cout<<node_ans[i]<<" ";
	// cout<<"\n";

	// for(int i = 0;i<n;i++)
	// 	cout<<height[i]<<" ";
	// cout<<"\n";

	cout<<ans-1<<"\n";

	return 0;
}
