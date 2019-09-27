// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
// https://www.geeksforgeeks.org/find-number-distinct-palindromic-sub-strings-given-string/

#include<bits/stdc++.h>

using namespace std;


//not distinct
int count_pallindromic_substring(string s){

	int n = s.length(), cnt = 0;

	vector<vector<bool>> dp(n,vector<bool>(n,false));

	for(int i = 0;i<n;i++){
		cnt++;
		dp[i][i] = true;
	}

	for(int l = 2;l<=n;l++){
		for(int i = 0;i<=n-l;i++){
			int j = i+l-1;
			if(l == 2 && s[i] == s[j]){
				cnt++;
				dp[i][j] = true;
			}
			else if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1];
				if(dp[i][j])
					cnt++;
			}
		}
	}
	return cnt;
}

int main(){

	string s = "abab";

	cout<<"count_pallindromic_substring: "<<count_pallindromic_substring(s)<<"\n";

	return 0;
}