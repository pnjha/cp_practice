// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c?show=progress
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	int t,n,tr=0,r=0,c=0;
	cin>>t;

	for(int k = 0;k<t;k++){
		cin>>n;
		int arr[n][n];
		tr = 0;
		r = 0;
		c = 0;

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>arr[i][j];
				if(i == j) tr += arr[i][j];
			}
		}

		unordered_map<int,int> p;

		for(int i = 0;i<n;i++){
			p.clear();
			for(int j = 0;j<n;j++){
				if(p.find(arr[i][j])!=p.end()) {
					r++;
					break;
				}
				p[arr[i][j]] = 1;
			}
		}

		for(int j = 0;j<n;j++){
			p.clear();
			for(int i = 0;i<n;i++){
				if(p.find(arr[i][j])!=p.end()) {
					c++;
					break;
				}
				p[arr[i][j]] = 1;
			}
		}

		p.clear();
		cout<<"Case #"<<k+1<<": "<<tr<<" "<<r<<" "<<c<<"\n";
	}


	return 0;
}
