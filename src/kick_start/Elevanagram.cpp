// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd/00000000001a286d
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool dfs(vector<ll>& arr, int num_digits, int op, ll sum){
	if(num_digits==0){
		if(sum%11==0) return true;
		return false;
	}
	bool flag = false;
	for(int i = 0;i<9;i++){
		if(arr[i]>0){
			arr[i]--;
			if(op==0) flag = dfs(arr,num_digits-1,1,sum-i-1);
			else if(op==1) flag = dfs(arr,num_digits-1,0,sum+i+1);
			arr[i]++;
			if(flag) return true;
		}
	}	
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);
	int t;cin>>t;
	for(int k = 1;k<=t;k++){
		ll num_digits = 0;
		bool flag = false;
		vector<ll> arr(9);
		for(int i = 0;i<9;i++) {
			cin>>arr[i];
			num_digits += arr[i];
		}

		for(int i = 0;i<9;i++){
			if(arr[i]>0){
				arr[i]--;
				flag = dfs(arr,num_digits-1,0,i+1);
				arr[i]++;
				if(flag) break;
			}
		}

		if(flag) cout <<"Case #" << k <<": "<<"YES"<<"\n";
		else cout <<"Case #" << k <<": "<<"NO"<<"\n";
	}	
	return 0;
}
