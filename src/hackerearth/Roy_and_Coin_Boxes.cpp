// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b,m;
	cin>>n>>m;

	vector<ll> arr(n,0);
	for(int i = 0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		arr[a]++;
		if(b+1<n) arr[b+1]--;
	}

	for(int i = 1;i<n;i++){
		arr[i] += arr[i-1];
	}

	// for(int i = 0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }cout<<"\n";

	int cnt[1000007];
	memset(cnt,0,sizeof(cnt));

	for(int i = 0;i<n;i++) cnt[arr[i]]++;
	for(int i = 1000005;i>=0;i--){
		cnt[i] += cnt[i+1];
	}

	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>a;
		cout<<cnt[a]<<"\n";
	}

	return 0;
}

/*
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2

6
0
0
4

*/