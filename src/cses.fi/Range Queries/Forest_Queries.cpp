// https://cses.fi/problemset/task/1652
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void print_arr(vector<vector<ll>>& arr){
	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<arr[0].size();j++){
			cout<<arr[i][j]<<" ";
		}cout<<"\n";
	}
}

int main(){
	
	// freopen("in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,x1,y1,x2,y2,ans=0;
	cin>>n>>q;

	vector<vector<ll>> arr(n,vector<ll>(n,0)); //0 means empty, 1 means tree
	char c;

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>c;
			arr[i][j] = c=='.'?0:1;
		}
	}

	for(int i = 1;i<n;i++) arr[0][i] += arr[0][i-1];
	for(int i = 1;i<n;i++) arr[i][0] += arr[i-1][0];

	for(int i = 1;i<n;i++){
		for(int j = 1;j<n;j++){
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}

	for(int i = 0;i<q;i++){
		cin>>x1>>y1>>x2>>y2;
		x1--,x2--,y1--,y2--;
		ans = arr[x2][y2] - ((y1-1)>=0?arr[x2][y1-1]:0) - ((x1-1)>=0?arr[x1-1][y2]:0) + ((x1-1>=0)&&(y1-1>=0)?arr[x1-1][y1-1]:0);
		cout<<ans<<"\n";
	}	

	return 0;
}

/*
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
*/