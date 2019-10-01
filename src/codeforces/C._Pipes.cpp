// https://codeforces.com/contest/1234/problem/C
 
#include<bits/stdc++.h>
 
using namespace std;
 
/*
| - |- -| _| L
1 2 3	4  5 6 
*/
 
vector<vector<int>> grid;
 
bool dfs(int prow, int pcol, int row, int col, int n){
 
	// cout<<row<<" "<<col<<"\n";
 
	if(row == 1 && col == n-1){
 
		if(grid[row][col] == 2 || grid[row][col] == 6)
			return true;
		return false;
	}
 
	int b = 0;
	bool flag = false;
 
	if(grid[row][col] == 2 || grid[row][col] == 1){
		
		grid[row][col] = 2;
 
		if(col+1<n){
 
			b = grid[row][col+1];
 
			if(b == 2 || b == 1){
 
				grid[row][col+1] = 2;
				flag = dfs(row,col,row,col+1,n);
			
			}else{
 
				if(row == 0) grid[row][col+1] = 4;
				else if(row == 1) grid[row][col+1] = 5;
				
				flag = dfs(row,col,row,col+1,n);
			}
 
			grid[row][col+1] = b;
			return flag;
		}
 
	}else if(grid[row][col] == 3){
	
		if(col+1<n){
 
			b = grid[row][col+1];
 
			if(b == 2 || b == 1){
 
				grid[row][col+1] = 2;
				flag = dfs(row,col,row,col+1,n);
			
			}else{
 
				if(row == 0) grid[row][col+1] = 4;
				else if(row == 1) grid[row][col+1] = 5;
				
				flag = dfs(row,col,row,col+1,n);
			}
 
			grid[row][col+1] = b;
			return flag;
		}
 
	}else if(grid[row][col] == 4){
 
		if(row == 0){
 
			b = grid[row+1][col];
 
			if(b != 1 && b != 2){
 
				grid[row+1][col] = 6;
				flag = dfs(row,col,row+1,col,n);
			}
 
			grid[row+1][col] = b;
			return flag;
		}
 
	}else if(grid[row][col] == 5){
 
		if(row == 1){
 
			b = grid[row-1][col];
 
			if(b != 1 && b != 2){
 
				grid[row-1][col] = 3;
				flag = dfs(row,col,row-1,col,n);
			}
 
			grid[row-1][col] = b;
			return flag;
		}
 
	}else if(grid[row][col] == 6){
		
		if(col+1<n){
 
			b = grid[row][col+1];
 
			if(b == 2 || b == 1){
 
				grid[row][col+1] = 2;
				flag = dfs(row,col,row,col+1,n);
			
			}else{
 
				grid[row][col+1] = 5;
				
				flag = dfs(row,col,row,col+1,n);
			}
 
			grid[row][col+1] = b;
			return flag;
		}
	}
 
	return false;
}
 
int main(){
 
	// freopen("input.txt","r",stdin);
 
	string str;
	int q,n,b;
 
	cin>>q;
 
	while(q--){
 
		cin>>n;
 
		grid.clear();
		grid.resize(2,vector<int>(n,0));
 
		for(int i = 0;i<2;i++){
			cin>>str;
			for(int j = 0;j<n;j++){
				grid[i][j] = int(str[j]-'0');
			}
		}
 
		// for(int i = 0;i<2;i++){
		// 	for(int j = 0;j<n;j++){
		// 		cout<<grid[i][j]<<" ";
		// 	}cout<<"\n";
		// }
 
 
		if(grid[0][0] == 1)
			grid[0][0] = 2;
		else if(grid[0][0] == 3 || grid[0][0] == 5 || grid[0][0] == 6)
			grid[0][0] = 4;
 
		bool flag = false;
 
		if(grid[0][0] == 2){
 
			if(n>1){
				
				b = grid[0][1];
 
				if(b == 1 || b == 2){
 
					grid[0][1] = 2;
					flag = dfs(0,0,0,1,n);
				}
				else{
 
					grid[0][1] = 4;
					flag = dfs(0,0,0,1,n);
				}
			}
			
		}else if(grid[0][0] == 4){
 
			b = grid[1][0];
 
			if(b != 1 && b != 2){
 
				grid[1][0] = 6;
				flag = dfs(0,0,1,0,n);
			}
		}
 
		// for(int i = 0;i<2;i++){
		// 	for(int j = 0;j<n;j++){
		// 		cout<<grid[i][j]<<" ";
		// 	}cout<<"\n";
		// }

		if(flag){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
 
	return 0;
}