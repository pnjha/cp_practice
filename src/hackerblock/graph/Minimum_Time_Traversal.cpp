// https://hack.codingblocks.com/app/contests/668/p/870

#include<bits/stdc++.h>

using namespace std;

//source destination distance
map<pair<int,int>,map<pair<int,int>,int>> graph;
map<pair<int,int>,int> distances;
map<pair<int,int>,bool> explored;

int dijsktra(pair<int,int> source,pair<int,int> destination){

	distances[source] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

	pq.push({0,source});

	int dist = 0;
	pair<int, int> p;

	while(!pq.empty()){

		dist = pq.top().first;
		p = pq.top().second;
		
		pq.pop();

		explored[p] = true;

		if(p == destination)
			break;

		for(auto node:graph[p]){
			if(!explored[node.first]){
				if(distances[node.first] > dist + graph[p][node.first]){
					distances[node.first] = dist + graph[p][node.first];
					pq.push({distances[node.first], {node.first}});
				}	
			}
		}
	}

	return distances[destination];
}

int calculate_manhattan_distance(int si,int sj,int ei,int ej){
	
	return abs(si-ei) + abs(sj-ej);
}

int main(){

	int t,n,si,sj,ei,ej,a,b,c,d,e,dist;
	pair<int,int> source,destination;

	cin>>t;

	for(int tt = 1;tt<=t;tt++){

		cin>>n;

		cin>>si>>sj>>ei>>ej;

		if(n == 0){
			cout<<"#"<<tt<<" : "<<calculate_manhattan_distance(si,sj,ei,ej)<<"\n";
			continue;
		}

		graph.clear();
		distances.clear();
		explored.clear();

		source = {si,sj};
		destination = {ei,ej};

		graph[source][destination] = calculate_manhattan_distance(si,sj,ei,ej);
		graph[destination][source] = calculate_manhattan_distance(si,sj,ei,ej);

		map<pair<int,int>,map<pair<int,int>,int>> temp;

		for(int i = 0;i<n;i++){
			cin>>a>>b>>c>>d>>e;
			for(auto k : graph){
				dist = calculate_manhattan_distance(k.first.first,k.first.second,a,b);
				graph[k.first][{a,b}] = dist;
				temp[{a,b}][k.first] = dist;
			}
			for(auto k : graph){
				dist = calculate_manhattan_distance(k.first.first,k.first.second,c,d);
				graph[k.first][{c,d}] = dist;
				temp[{c,d}][k.first] = dist;
			}
			for(auto a : temp){
				graph[a.first] = a.second;
				// cout<<a.second->first<<"\n";
				// graph[a.first][a.second.first] = a.second.second;
			}
			graph[{a,b}][{c,d}] = e;
			graph[{c,d}][{a,b}] = e;
			temp.clear();
		}

		for(auto a: graph){
			distances[a.first] = INT_MA;X
			explored[a.first] = false;
		}

		cout<<"#"<<tt<<" : "<<dijsktra(source,destination)<<"\n";
	}

	return 0;
}

/*

1
3
20 20 100 100
35 35 50 50 0
30 30 25 25 0
40 40 60 60 100

*/