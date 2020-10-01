#include <bits/stdc++.h>

using namespace std;
int graph[15][15];
int dp[30000][15];
int all_visited;

long tsp(int mask,int node,int n){
    if(mask==all_visited) return graph[node][0];
    long ans=INT_MAX;
    if(dp[mask][n]!=-1) return dp[mask][node];
    for(int i = 0;i<n;i++){
        if((mask&(1<<i))==0){
            ans = min(ans, graph[node][i]+tsp((mask|(1<<i)),i,n));
        }
    }
    return dp[mask][node] = ans;
}

int main() {
	int t,n,mask;
	//freopen("input","r",stdin);
	cin>>t;
	while(t--){
	    cin>>n;
	   // graph.resize(n,vector<int>(n,-1));
	    memset(dp,-1,sizeof(dp));
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            cin>>graph[i][j];
	        }
	    }
	    all_visited = (1<<n)-1;
	    mask=1;
	    cout<<tsp(mask,0,n)<<"\n";
	}
	return 0;
}