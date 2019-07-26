#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<char>>& grid,int row,int col){
    cout<<row<<" "<<col<<"\n";
    if(row<0||col<0||row>=grid.size()||col>=grid[row].size()||grid[row][col]=='X'||grid[row][col]=='S')
        return;
    
    grid[row][col] = 'S';
    
    dfs(grid,row-1,col);
    dfs(grid,row,col-1);
    dfs(grid,row+1,col);
    dfs(grid,row,col+1);
}

int main() {
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> grid(n,vector<char>(m));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[i].size();j++){
            if((i==0||j==0||i==grid.size()-1||j==grid[i].size()-1)&&grid[i][j]=='O'){
                dfs(grid,i,j);
            }
        }
    }
    
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]=='X')
                cout<<grid[i][j];
            else if(grid[i][j] == 'S')
                cout<<'O';
            else
                cout<<'X';
        }
        cout<<"\n";
    }
    
    return 0;
}
