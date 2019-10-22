// https://cses.fi/problemset/task/1130
#include<bits.stdc++.h>

using namespace std;


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input","r",stdin);

	int n,a,b;
	cin>>n;
	vector<vector<int>> tree(n);
	vector<int> degree(n);

	for(int i = 0;i<n;i++){
		cin>>a>>b;
		a--,b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
		degree[a]++, degree[b]++;
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for(int i = 0;i<degree.size();i++){
		
	}

	return 0;
}
