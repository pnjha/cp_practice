#include<bits/stdc++.h>

using namespace std;

int min_edit_distance(string a,string b){

	vector<vector<int>> dp(a.length(),vector<int>(b.length(),0));

	for(int i = 0;i<dp.size();i++){

		for(int j = 0;j<dp[i].size();j++){

			if(i == 0 && j == 0){

				if(a[i] == b[j]){
					dp[i][j] = 0;
				}else{
					dp[i][j] = 1;
				}

			}else if(i == 0){

				if(a[i] == b[j]){
					dp[i][j] = dp[i][j-1];
				}else{
					dp[i][j] = dp[i][j-1] + 1;
				}

			}else if(j == 0){

				if(a[i] == b[j]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = dp[i-1][j] + 1;
				}

			}else{

				if(a[i] == b[j]){
					dp[i][j] = dp[i-1][j-1];
				}else{
					dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
				}
			}
		}
	}

	return dp[dp.size()-1][dp[0].size()-1];
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	string a,b;
	cin>>a>>b;

	cout<<min_edit_distance(a,b)<<"\n";

	return 0;
}
