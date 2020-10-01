// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209aa0?show=progress
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

void printarr(){
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@\n";
	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<arr.size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

int dp[52][52][1000];

bool dfs(int row, int col, int tr, int n){

	// cout<<row<<" "<<col<<" "<<tr<<" \n";
	// printarr();

	if(tr == 0 && row == n && col == 0) return true;
	if(tr < 0) return false;
	// if(row<0||col<0||row>=n||col>=n) return false;
	if(col == n) return dfs(row+1,0,tr,n);

	if(dp[row][col][tr]!=-1) return dp[row][col][tr];

	unordered_map<int,int> p;
	for(int i = 0;i<col;i++) p[arr[row][i]] = 1;
	for(int i = 0;i<row;i++) p[arr[i][col]] = 1;

	for(int i = 0;i<n;i++){
		if(p.find(i+1)==p.end()){
			arr[row][col] = i+1;
			if(dfs(row,col+1,(row==col?tr-(i+1):tr),n)){
				dp[row][col][tr] = 1;				
				return true;
			}
		}
	}	
	
	dp[row][col][tr] = 0;				
	return false;;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	bool flag = false;
	int t,n,tr=0;
	cin>>t;

	for(int k = 0;k<t;k++){
		cin>>n>>tr;
		
		arr.clear();
		arr.resize(n,vector<int>(n,0));
		memset(dp,-1,sizeof(dp));
		flag = false;

		for(int i = 0;i<n;i++){
			// cout<<i<<"\n";
			arr[0][0] = i+1;
			if(dfs(0,1,tr-arr[0][0],n)){
				flag = true;
				break;
			}
		}

		if(flag){
			cout<<"Case #"<<k+1<<": POSSIBLE\n";
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		else
			cout<<"Case #"<<k+1<<": IMPOSSIBLE\n";
			
	}


	return 0;
}
