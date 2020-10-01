#include<bits/stdc++.h>

using namespace std;

int max(int a,int b){
	return a>b?a:b;
}

int lcs(string text,string pattern){

	vector<vector<int>> arr(text.length()+1,vector<int>(pattern.length()+1,0));

	for(int i = 1;i<=text.length();i++){
		for(int j = 1;j<=pattern.length();j++){
			if(text[i-1]==pattern[j-1]){
				arr[i][j] = arr[i-1][j-1]+1;
			}else{
				arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
			}
		}
	}
	return arr[text.length()][pattern.length()];
}


int main(){

	string text = "AGGTAB";
	string pattern = "GXTXAYB";

	cout<<lcs(text,pattern)<<"\n";

	return 0;
}
