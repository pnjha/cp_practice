#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x,temp1,temp2;
	cin>>n>>x;

	map<pair<int,int>,bool> traps;

	for(int i = 0;i<x;i++){
		cin>>temp1>>temp2;
		traps[{temp1,temp2}] = true;
	}

	if(traps[{n,n}]||traps[{1,1}]){
		cout<<"0\n";
		return 0;
	}

	// vector<vector<long long int>> dp(n+1,vector<long long int>(n+1,0));

	vector<long long int> prev(n+1,0);
	vector<long long int> curr(n+1,0);

	int a = 0,b = 0;

	for(int i = 1;i<n+1;i++){

		for(int j = 1;j<n+1;j++){

			a = 0,b = 0;
			
			if(i==1&&j==1){

				// prev[j] = 1;
				curr[j] = 1;

			}else if(i == 1){

				if(!traps[{i,j-1}]){
					b = curr[j-1];
				}

				curr[j] = b%MOD;
			
			}else if(j == 1){

				if(!traps[{i-1,j}]){
					a = prev[j];
				}

				curr[j] = a%MOD;

			}else{


				if(!traps[{i-1,j}]){
					a = prev[j];
				}

				if(!traps[{i,j-1}]){
					b = curr[j-1];
				}

				curr[j] = (a%MOD+b%MOD)%MOD;

			}

		}

		prev = curr;
		// prev.swap(curr);
		curr.clear();
	}

	cout<<prev[n]<<"\n";

	return 0;
}
