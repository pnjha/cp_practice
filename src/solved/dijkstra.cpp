#include <bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;


void dj(vector<pair<int,int> > adj[], int V, int src){
    
    priority_queue< pair<int,int>, 
    vector <pair<int,int>> , greater<pair<int,int>> > pq;
    vector<int> distance(V, INF);
 
    pq.push(make_pair(0, src));
    distance[src] = 0;
 
    while(!pq.empty(){
        int u = pq.top().second;
        pq.pop();
 
        for(auto x : adj[u]){

            int v = x.first;
            int weight = x.second;
            
            if (distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    
    for (int i = 0; i < V; ++i){
        if(distance[i]<INF&&distance[i]!=0){
            printf("%d ",distance[i]);
        }else if(distance[i]==INF&&distance[i]!=0)
            cout<<"-1 ";
    }
        
}

int main(){
    int t=0;
    cin>>t;
    
    while(t--){
        
        int vertices,edges,source,a,b,weight;
        
        cin>>vertices>>edges;
        
        vector<pair<int,int>> graph[vertices];

        for(int i=0;i<edges;i++){
            cin>>a>>b>>weight;
            
            graph[a-1].push_back(make_pair(b-1, weight));
            graph[b-1].push_back(make_pair(a-1, weight));
        }
        
        cin>>source;
        
        dj(graph,vertices,source-1);
        
        cout<<"\n";
    }
    
    return 0;
}