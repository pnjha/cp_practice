#include<bits/stdc++.h>

using namespace std;

int main(){

	// int n = 5;

	// vector<vector<int>> grid(n+1,vector<int>(n+1,0));
 
	// for(int i = 1;i<=n;i++){
	// 	for(int j = 1;j<=n;j++){
	// 		if(j%2==1&&i%2==1){
	// 			grid[i][j] = max(i,j) * max(i-1,j-1) + (j-i) + 1;
			
	// 		}else if(j%2==1&&i%2==0){
	// 			grid[i][j] = max(i,j) * max(i-1,j-1) + abs(j-i) + 1;
			
	// 		}else if(j%2==0&&i%2==0){
	// 			grid[i][j] = max(i,j) * max(i-1,j-1) + (i-j) + 1;
			
	// 		}else if(j%2==0&&i%2==1){
	// 			grid[i][j] = max(i,j) * max(i-1,j-1) - abs(i-j) + 1;
	// 		}
	// 	}
	// }

	// for(int i = 1;i<=n;i++){
	// 	for(int j = 1;j<=n;j++){
	// 		cout<<grid[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	long long int t,i,j;
	cin>>t;

	while(t--){

		cin>>i>>j;

		if(j%2==1&&i%2==1){
			cout<<max(i,j) * max(i-1,j-1) + (j-i) + 1<<"\n";
		
		}else if(j%2==1&&i%2==0){
			cout<<max(i,j) * max(i-1,j-1) + abs(j-i) + 1<<"\n";
		
		}else if(j%2==0&&i%2==0){
			cout<<max(i,j) * max(i-1,j-1) + (i-j) + 1<<"\n";
		
		}else if(j%2==0&&i%2==1){
			cout<<max(i,j) * max(i-1,j-1) - abs(i-j) + 1<<"\n";
		}
	}

	return 0;
}
