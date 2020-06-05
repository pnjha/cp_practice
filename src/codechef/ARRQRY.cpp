// https://www.codechef.com/KA19MOS/problems/ARRQRY
#include<bits/stdc++.h>
#define ll long long int 
#define MOD 998244353

using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t;
	cin>>t;

	while(t--){

		ll n,m,ans = 0,temp;
		cin>>n>>m;

		vector<ll> a(n),b(m);

		for(int i = 0;i<n;i++) cin>>a[i];
		for(int i = 0;i<m;i++) cin>>b[i];	

		for(int i = 0;i<n;i++) a[i] = (i==0)?a[i]:(a[i]+a[i-1])%MOD;
		for(int i = 0;i<m;i++) b[i] = (i==0)?b[i]:(b[i]+b[i-1])%MOD;

		ans = (a[n-1] * b[m-1])%MOD;

		ll q,w,l,r,x;
		cin>>q;

		for(int i = 0;i<q;i++){
			cin>>w;
			if(w==1){
				cin>>l>>r>>x;
				l--,r--;
				ans = (ans + ((((r-l+1)*x)%MOD) * b[m-1])%MOD)%MOD;
				a[n-1] += ((r-l+1)*x)%MOD;
			}else if(w==2){
				cin>>l>>r>>x;
				l--,r--;
				ans = (ans + ((((r-l+1)*x)%MOD) * a[n-1])%MOD)%MOD;
				b[m-1] += ((r-l+1)*x)%MOD;
			}else if(w==3){
				cout<<ans<<"\n";
			}
		}
	}

	return 0;
}
