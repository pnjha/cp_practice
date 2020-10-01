//samsung question
int ans = 0;

void dfs(board,word,row,col,index){
	
	if(index>=wordlen){
		ans++;
		return;
	}

	for(int i = 0;i<8;i++){
		nx = row + dx[i];
		ny = col + dy[i];
		if(nx<m&&ny<n&&m>=0&&n>=0&&!visited[nx][ny]&&board[nx][ny]==word[index]){
			visited[nx][ny] = true;
			dfs(board,word,nx,ny,index+1);
			visited[nx][ny] = false;
		
	}}
}

main(){
	
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(board[i][j] == word[0]){
				visited[i][j] = true;
				dfs(board,word,i,j,1);
				visited[i][j] = false;
			}
		}
	}
}