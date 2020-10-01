// https://www.codechef.com/JAN20B/problems/CHFDORA
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t,n,m;
	cin>>t;
	while(t--){
		ll ans = 0;
		cin>>n>>m;

		vector<vector<int>> arr(n,vector<int>(m,0));

		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cin>>arr[i][j];
			}
		}

		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				int a=j,b=i,c=j,d=i;
				cout<<i<<" "<<j<<"\n";
				// cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
				while(a>=0&&b>=0&&c<m&&d<n){
					cout<<"here\n";
					if(arr[i][a]==arr[i][c]&&arr[b][j]==arr[d][j]) ans++;
					else break;
					a--,b--,c++,d++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
1
3 3
2 1 2
1 1 1
2 1 2
*/