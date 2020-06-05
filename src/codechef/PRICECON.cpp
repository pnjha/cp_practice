// https://www.codechef.com/JUNE20B/problems/PRICECON
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;

	while(t--){

		int n,k,a,ans = 0;
		cin>>n>>k;

		for(int i = 0;i<n;i++){
			cin>>a;
			if(a > k)
				ans += a-k;
		}

		cout<<ans<<"\n";
	}

	return 0;
}


/*
3
5 4
10 2 3 4 5
7 15
1 2 3 4 5 6 7
5 5
10 9 8 7 6

xyxyyx
xyyxyx
*/