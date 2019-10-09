// https://codeforces.com/contest/1238/problem/C
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t,n,r,a;
	cin>>t;

	while(t--){

		cin>>n>>r;

		vector<ll> arr(n+1,0);

		for(int i = 0;i<r;i++){
			cin>>a;
			arr[a] = 1;
		}

		ll cnt = 0,i = n;

		while(i>=0){

			if(i-2>=0&&i-1>=0&&arr[i-1]==1&&arr[i-2]==0){
				cnt++;
				i = i-2;
			}else if(i-2>=0&&i-1>=0&&arr[i-1]==1&&arr[i-2]==1){
				i = i - 2;
			}else if(i-1>=0&&arr[i-1]==0){
				i = i-1;
			}

			if(i<=0)
				break;
		}

		cout<<cnt<<"\n";
	}

	return 0;
}
