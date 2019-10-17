// https://www.codechef.com/OCT19B/problems/EVEDG
#include<bits/stdc++.h>

using namespace std;

int main(){

	int m,n,t,a,b;
	cin>>t;

	vector<vector<int>> graph;

	while(t--){

		cin>>n>>m;
		graph.clear(), graph.resize(n);

		for(int i = 0;i<m;i++){
			cin>>a>>b;
			a--,b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int odd_node=-1, D = 0, even_node,neigh;

		for(int i = 0;i<n;i++){
			if(graph[i].size()%2==1){
				odd_node = i;
			}else{
				even_node = i;
			}
			D += graph[i].size();
		}

		if((D/2)%2==0){
			cout<<"1\n";
			for(int i = 0;i<n;i++){
				cout<<"1 ";
			}cout<<"\n";
		}else{

			if(odd_node!=-1){
				cout<<"2\n";
				for(int i = 0;i<n;i++){
					if(i!=odd_node)
						cout<<"1 ";
					else
						cout<<"2 ";
				}cout<<"\n";	
			}else{
				cout<<"3\n";
				neigh = graph[even_node][0];
				for(int i = 0;i<n;i++){
					if(i!=even_node&&i!=neigh)
						cout<<"1 ";
					else if(i==even_node)
						cout<<"2 ";
					else if(i==neigh)
						cout<<"3 ";
				}cout<<"\n";
			}
		}
	}

	return 0;
}
