#include<bits/stdc++.h>

using namespace std;

int ans = 0;

bitset<8> col;
bitset<16> LB_RU;
bitset<16> LU_RB;

void dfs(vector<string>& board, int row_index){

	if(row_index == 8){
		ans++;
		return;
	}

	for(int j = 0;j<board[row_index].length();j++){
		if(board[row_index][j]!='*'&&col[j]==0&&LB_RU[row_index+j]==0&&LU_RB[8+row_index-j]==0){
			col[j] = 1;
			LB_RU[row_index+j] = 1;
			LU_RB[8+row_index-j] = 1;
			dfs(board,row_index+1);
			col[j] = 0;
			LB_RU[row_index+j] = 0;
			LU_RB[8+row_index-j] = 0;
		}			
	}	

}

int main(){

	ios_base::sync_with_stdio(NULL);

	ans = 0;

	vector<string> board(8);

	for(int i = 0;i<8;i++){
		cin>>board[i];
	}

	for(int j = 0;j<board[0].length();j++){
		if(board[0][j]!='*'){
			col[j] = 1;
			LB_RU[j] = 1;
			LU_RB[8-j] = 1;
			dfs(board,1);
			col[j] = 0;
			LB_RU[j] = 0;
			LU_RB[8-j] = 0;
		}			
	}

	cout<<ans<<"\n";
	return 0;
}
