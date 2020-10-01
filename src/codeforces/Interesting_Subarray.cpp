// http://m1.codeforces.com/contest/1270/problem/B
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t,n,a,b;
	cin>>t;

	while(t--){
		cin>>n;
		vector<ll> arr(n);
		for(int i = 0;i<n;i++) cin>>arr[i];
		bool flag = false;
		for(int i = 0;i<n-1;i++){
			if(abs(arr[i]-arr[i+1])>1){
				flag = true;
				a = i+1, b = i+2;
				break;
			}
		}
		if(!flag) cout<<"NO\n";
		else{
			cout<<"YES\n";
			cout<<a<<" "<<b<<"\n";
		}
	}

	return 0;
}
