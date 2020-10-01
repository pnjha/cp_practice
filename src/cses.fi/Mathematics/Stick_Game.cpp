// https://cses.fi/problemset/task/1729

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,k;
	cin>>n>>k;

	vector<ll> coins(k,-1);
	vector<int> ans(n+1,0);

	for(int i = 0;i<k;i++)
		cin>>coins[i];

	ans[0] = 0;
	bool flag = false;

	for(int j = 1;j<=n;j++){
		for(int i = 0;i<k;i++){
			if(j-coins[i]>=0){
				if(ans[j-coins[i]]%2==0){
					ans[j] = ans[j-coins[i]] + 1; 
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		flag = false;
	}

	for(int i = 1;i<=n;i++){
		if(ans[i]%2==1)
			cout<<'W';
		else
			cout<<'L';
	}cout<<endl;

	return 0;
}
