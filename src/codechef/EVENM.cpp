// https://www.codechef.com/JUNE20B/problems/EVENM

#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t,n;
	vector<vector<int>> arr;

	cin>>t;
	while(t--){
		cin>>n;
		arr.clear();
		arr.resize(n,vector<int>(n,0));
		int cnt = 1,dir = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				arr[i][j] = cnt;
				if(dir==0)
					cnt++;
				else
					cnt--;
			}
			dir = 1 - dir;
			if(dir == 1)
				cnt += n-1;
			else
				cnt += n+1;
		}

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	return 0;
}