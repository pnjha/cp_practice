#include<bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void bfs(int index){
    queue<int> q;
    q.push(index);
    while(!q.empty()){
        int temp = q.front();
        visited[temp] = true;
        cout<<temp<<" ";
        for(int i=0;i<graph[temp].size();i++){
            if(visited[graph[temp][i]]==false){
                q.push(graph[temp][i]);
                visited[graph[temp][i]] = true;
            }
        }
        q.pop();
    }
}

int main(){
    
    int vertices, edges;
    cin >> vertices >> edges;

    visited.assign(vertices,false);
    graph.assign(vertices,vector<int>());
    int a,b;
    for(int i=0;i<edges;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); //comment this line for directed graph
    }
    
    for(int i=0;i<vertices;i++){
        if(visited[i]==false){
            bfs(i);
        }
    }
    return 0;
}