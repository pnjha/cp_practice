#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

unordered_map<string,int> dict;

// unordered_map<int, long long int> memo;

// int dfs(string& str,int index){

// 	if(index == str.length()){
// 		return 1;
// 	}
	
// 	if(memo.find(index)!=memo.end()){	
// 		return memo[index];
// 	}

// 	string temp;
// 	long long int t=0,cnt=0;

// 	for(int i = index;i<str.length();i++){

// 		temp = str.substr(index,i+1-index);

// 		if(dict.find(temp)!=dict.end()){

// 			if(memo.find(i+1)!=memo.end()){	
			
// 				cnt = (cnt + memo[i+1])%MOD;
			
// 			}else{

// 				cnt = (cnt + dfs(str,i+1))%MOD;
// 			}
// 		}
// 	}	

// 	memo[index] = cnt;

// 	return cnt;
// }
// int main(){

// 	freopen("input.txt","r",stdin);
// 	// freopen("output.txt","w",stdout);

// 	int clk = clock();

// 	ios_base::sync_with_stdio(NULL);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	string str,temp;
// 	cin>>str;

// 	long long int n,cnt=0,t=0;
// 	cin>>n;

// 	for(int i = 0;i<n;i++){
// 		cin>>temp;
// 		dict[temp] = true;
// 	}

// 	for(int i = 0;i<str.length();i++){

// 		temp = str.substr(0,i+1);

// 		if(dict.find(temp)!=dict.end()){
// 			if(memo.find(i+1)!=memo.end()){	
			
// 				t = memo[i+1];
			
// 			}else{

// 				t = dfs(str,i+1);
// 			}
// 			cnt = (cnt+t)%MOD;
// 		}
// 	}

// 	cout<<cnt<<"\n";

// 	cout<<"Time: "<<(clock() - clk)<<"\n";

// 	return 0;
// }

int main(){

	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int clk = clock();

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string str,temp;
	cin>>str;

	long long int n,cnt=0,t=0;
	cin>>n;

	for(int i = 0;i<n;i++){
		cin>>temp;
		dict[temp] = true;
	}

	vector<vector<int>> dp(str.length(),vector<int>(str.length(),0));

	for(int i = 0;i<str.length();i++){

		for(int j = i+1;j<str.length();j++){

			temp = str.substr(i,j-i-1);

			if(dict.find(temp)!=dict.end()){

				dp[i][j] = (dp[i][j] + 1)%MOD;

			}	
		}
	}

	int ans = 1;
	// bool flag = false;

	for(int i = 0;i<str.length();i++){

		cnt = 0;

		for(int j = 0;j<str.length();j++){

			cnt = (cnt + dp[j][i])%MOD;

		}

		if(cnt>0)
			ans = (ans * cnt)%MOD;
	}	

	cout<<ans<<"\n";

	cout<<"Time: "<<(clock() - clk)<<"\n";

	return 0;
}