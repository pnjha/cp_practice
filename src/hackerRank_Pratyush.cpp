//https://www.hackerrank.com/contests/aps-2018-lab-10/challenges/pratyush-the-runner-p/problem
#include<bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<int> temp;
vector<vector<int>> graph;
vector<vector<int>> reGraph;
vector<vector<int>> components;
stack<int> vertexStack;
vector<int> ind;
vector<bool> cycle;
int edgesInCycle = 0;

void fillStack(int index){
    
    visited[index] = 1;
    
    for(int i=0;i<graph[index].size();i++){
        if(visited[graph[index][i]]==0)
            fillStack(graph[index][i]);
    }
    
    vertexStack.push(index);    
}


void findComponent(int index){
    
    visited[index] = 1;
    
    temp.push_back(index);
    ind[index] = reGraph[index].size();
    for(int i=0;i<reGraph[index].size();i++){
        if(visited[reGraph[index][i]]==0)
            findComponent(reGraph[index][i]);
    }
     
}

bool dfs(int index){
    
    for(int i=0;i<graph[index].size();i++){
        if(cycle[graph[index][i]]==true){
            cycle[index] = true;
            return true;
        }else{
            dfs(graph[index][i]);
        }
    }
    
    return false;
}


void getEdgesInCycle(){
    
    for(int i=0;i<cycle.size();i++){
        if(cycle[i]){
            edgesInCycle += ind[i];
        }else{
            if(dfs(i))
                edgesInCycle += ind[i];
        }
    }
}

int main() {
    
    int t=0;
    cin>>t;
    
    while(t--){
        int vertices,edges,v1,v2;
        
        cin>>vertices>>edges;
        
        ind.resize(vertices,0);
        cycle.resize(vertices,false);
        graph.resize(vertices);
        reGraph.resize(vertices);
        visited.resize(vertices,0);
    
        for(int i=0;i<edges;i++){
            cin>>v1>>v2;
            graph[v1-1].push_back(v2-1);
            reGraph[v2-1].push_back(v1-1);
        }
    
        for(int i=0;i<vertices;i++){
            if(visited[i]==0){
                fillStack(i);
            }
        }
        
        visited.assign(vertices,0);
        
        while(vertexStack.empty()==false){
            int p = vertexStack.top();
            vertexStack.pop();
            if(visited[p]==0){
                findComponent(p);
                components.push_back(temp);    
            }
            
            temp.clear();
        }
        
        for(int i=0;i<components.size();i++){
            if(components[i].size()>1){
                for(int j=0;j<components[i].size();j++){
                    cycle[components[i][j]] = true;
                }
            }
        }
        
        getEdgesInCycle();
        
        // for(int i=0;i<cycle.size();i++)
        //     cout<<cycle[i]<<" ";
        // cout<<"\n";
        
        cout<<edgesInCycle<<"\n";
        
        edgesInCycle = 0;
        ind.clear();
        cycle.clear();
        graph.clear();
        reGraph.clear();
        visited.clear();
        temp.clear();
        components.clear();
    }
    
    return 0;
}
