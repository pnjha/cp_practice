class Solution {
public:
    
    vector<vector<int>> visited;
    
    void dfs(vector<vector<int>>& grid, int row, int col, bool dir){
        int n = grid.size();
        if(dir){
            visited[row][col] = 1;
            if(row+1<n&&col<n&&visited[row+1][col]!=1&&grid[row+1][col]!=-1) dfs(grid,row+1,col,dir);
            if(row<n&&col+1<n&&visited[row][col+1]!=1&&grid[row][col+1]!=-1) dfs(grid,row,col+1,dir);
        }else{
            visited[row][col] = 2;
            if(row-1>=0&&visited[row-1][col]!=2&&grid[row-1][col]!=-1) dfs(grid,row-1,col,dir);
            if(col-1>=0&&visited[row][col-1]!=2&&grid[row][col-1]!=-1) dfs(grid,row,col-1,dir);
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        visited.clear(); 
        visited.resize(n,visited<bool>(n,0));
        dfs(grid,0,0,true);
        dfs(grid,n-1,n-1,false);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]>0) ans += 1;
            }
        }
        return ans;
    }
};
