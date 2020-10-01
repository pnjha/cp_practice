// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define INF 1e7

#define ll long long int
using namespace std;

vector<vector<ll>> graph;

void floyd_warshall(){

	int n = graph.size();
	vector<vector<ll>> temp(n,vector<ll>(n,0));

	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				temp[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
		graph = temp;
		temp.clear();
		temp.resize(n,vector<ll>(n,0));		
	}

}

int main(){

	int t,n,a;
	cin>>t;

	while(t--){
		cin>>n;

		graph.clear();
		graph.resize(n,vector<ll>(n,0));

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>graph[i][j];
			}
		}

		floyd_warshall();

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(graph[i][j]!=INF)
					cout<<graph[i][j]<<" ";
				else
					cout<<"INF ";
			}
			cout<<"\n";
		}		
	}

	return 0;
}
