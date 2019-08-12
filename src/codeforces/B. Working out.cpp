// https://codeforces.com/contest/429/problem/B

#include<bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>>& arr){
	for(int i = 1;i<arr.size();i++){
		for(int j = 1;j<arr.size();j++){
			cout<<arr[i][j]<<" ";
		}cout<<"\n";
	}
	cout<<"\n";
}

int solve(vector<vector<int>>& arr){

	int n = arr.size(),m = arr[0].size();

	//boy's moves
	vector<vector<int>> UL(n+1,vector<int>(m+1,0));
	vector<vector<int>> BR(n+1,vector<int>(m+1,0));
	
	//girl's moves
	vector<vector<int>> BL(n+1,vector<int>(m+1,0));
	vector<vector<int>> UR(n+1,vector<int>(m+1,0));

	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<m+1;j++){
			UL[i][j] = max(UL[i-1][j], UL[i][j-1]) + arr[i-1][j-1];
		}
	}

	for(int i = n;i>0;i--){
		for(int j = m;j>0;j--){

			if(i == n && j == m){
				BR[i][j] = arr[i-1][j-1];
			}else if(i == n){
				BR[i][j] = BR[i][j+1] + arr[i-1][j-1];
			}else if(j == m){
				BR[i][j] = BR[i+1][j] + arr[i-1][j-1];
			}else{
				BR[i][j] = max(BR[i][j+1], BR[i+1][j]) + arr[i-1][j-1];
			}
		}
	}

	for(int i = n;i>0;i--){
		for(int j = 1;j<m+1;j++){
			
			if(i == n && j == 1){
				BL[i][j] = arr[i-1][j-1];
			}else if(i == n){
				BL[i][j] = BL[i][j-1] + arr[i-1][j-1];
			}else if(j == 1){
				BL[i][j] = BL[i+1][j] + arr[i-1][j-1];
			}else{
				BL[i][j] = max(BL[i][j-1], BL[i+1][j]) + arr[i-1][j-1];
			}
		}
	}

	for(int i = 1;i<n+1;i++){
		for(int j = m;j>0;j--){
			
			if(i == 1 && j == m){
				UR[i][j] = arr[i-1][j-1];
			}else if(i == 1){
				UR[i][j] = UR[i][j+1] + arr[i-1][j-1];
			}else if(j == m){
				UR[i][j] = UR[i-1][j] + arr[i-1][j-1];
			}else{
				UR[i][j] = max(UR[i][j+1], UR[i-1][j]) + arr[i-1][j-1];
			}	
		}
	}	

	// cout<<"\n";
	// print_matrix(UL);
	// print_matrix(UR);
	// print_matrix(BL);
	// print_matrix(BR);

	int ans = INT_MIN,a,b;

	for(int i = 2;i<n;i++){
		for(int j = 2;j<m;j++){

			a = UL[i][j-1] + UR[i-1][j] + BL[i+1][j] + BR[i][j+1];
			b = UL[i-1][j] + UR[i][j+1] + BL[i][j-1] + BR[i+1][j];
			ans = max(ans,max(a,b));

			// ans = max(ans,(UL[i][j] + UR[i][j] + BL[i][j] + BR[i][j] - 4*arr[i-1][j-1]));
		}
	}

	return ans;
}

int main(){

	int n,m;
	cin>>n>>m;

	vector<vector<int>> arr(n,vector<int>(m,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	cout<<solve(arr)<<"\n";

	return 0;
}
