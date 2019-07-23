// ??L???R???L??U??R??R??R???D??U?UU??D?D?LD????D?

#include<bits/stdc++.h>

using namespace std;

int ans = 0;
int col_prun = 0;
int row_prun = 0;

vector<vector<bool>> visited;
vector<int> row_sum;
vector<int> col_sum;

void dfs(string& moves,int row,int col,int cnt,int index){

	// cout<<row<<" "<<col<<" "<<cnt<<" "<<index<<"\n";

	if(index>=moves.length()){
		ans++;
		return;
	}

	// cout<<"here\n";

	if(row<0||col<0||row>=7||col>=7||index>=moves.length()||visited[row][col])
		return;

	if(row_sum[row]+1 == 7){
		for(int i = 0;i<row;i++){
			if(row_sum[i]!=7){
				row_prun++;
				cout<<"row: "<<row_prun<<" \n";	
				return;
			}
		}
	}

	if(col_sum[col]+1 == 7){
		for(int i = col+1;i<7;i++){
			if(col_sum[i]!=7){
				col_prun++;
				cout<<"col: "<<col_prun<<" \n";
				return;
			}
		}
	}

	// ans++;
	// cout<<ans<<"\n";	

	visited[row][col] = true;
	
	row_sum[row]++;
	col_sum[col]++;

	if((moves[index]=='R'||moves[index]=='?')){

		dfs(moves,row,col+1,cnt+1,index+1);

	}

	if((moves[index]=='D'||moves[index]=='?')){

		dfs(moves,row+1,col,cnt+1,index+1);

	}

	if((moves[index]=='U'||moves[index]=='?')){

		dfs(moves,row-1,col,cnt+1,index+1);

	}

	if((moves[index]=='L'||moves[index]=='?')){

		dfs(moves,row,col-1,cnt+1,index+1);

	}

	visited[row][col] = false;
	row_sum[row]--;
	col_sum[col]--;

}

int main(){

	string moves;
	cin>>moves;

	visited.clear();
	visited.resize(7,vector<bool>(7,false));

	row_sum.clear();
	row_sum.resize(7,0);

	col_sum.clear();
	col_sum.resize(7,0);

	dfs(moves,0,0,1,0);

	cout<<ans<<"\n";

	return 0;
}
