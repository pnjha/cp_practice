// using BFS, faster than using DFS

bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}

// DFS

vector<vector<int>> graph;
vector<int> visited;

bool dfs(int node){
    if(visited[node]==1) return true;
    
    visited[node] = 1;
    bool flag = false;
    
    for(int i = 0;i<graph[node].size();i++){
        flag = dfs(graph[node][i]);
        if(flag) return true;
    }
    visited[node] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    bool flag = true;
    
    visited.clear();
    visited.resize(numCourses,0);
    
    graph.clear();
    graph.resize(numCourses);
    
    for(int i = 0;i<prerequisites.size();i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    
    for(int i = 0;i<numCourses;i++){
        if(visited[i]==0){
            flag = dfs(i);
            if(flag) return false;
        }
    }
    
    return true;
}