#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main(){

	int n;
	cin>>n;

	vector<string> grid(n);
	
	for(int i = 0;i<grid.size();i++)
		cin>>grid[i];

	vector<vector<long long int>> dp(grid.size()+1,vector<long long int>(grid[0].size()+1,0));
	int a,b;

	for(int i = 1;i<dp.size();i++){

		if(grid[grid.size()-1][grid[0].size()-1] == '*'){
			break;
		}

		for(int j = 1;j<dp[i].size();j++){

			// cout<<i<<" "<<j<<"\n";

			if(i==1&&j==1){

				if(grid[i-1][j-1]!='*'){
			
					dp[i][j] = 1;
			
				}
			
			}else if(i == 1){

				if(grid[i-1][j-2]!='*')
					b = dp[i][j-1];
				else
					b = 0;			

				dp[i][j] = b%MOD;

			}else if(j == 1){

				if(grid[i-2][j-1]!='*')
					a = dp[i-1][j];
				else
					a = 0;

				dp[i][j] = a%MOD;

			}else{

				if(grid[i-2][j-1]!='*')
					a = dp[i-1][j];
				else
					a = 0;

				if(grid[i-1][j-2]!='*')
					b = dp[i][j-1];
				else
					b = 0;

				dp[i][j] = (a%MOD + b%MOD)%MOD;				
			}
			// cout<<"done\n";
		}
	}


	cout<<dp[dp.size()-1][dp[0].size()-1]<<"\n";
	return 0;
}
