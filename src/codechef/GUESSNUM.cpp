// https://www.codechef.com/LTIME79A/problems/GUESSNUM
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t,a,m;
	cin>>t;

	while(t--){
		cin>>a>>m;
		ll s = (m-(m%a))/a, d = 0;
		vector<ll> ans;
		while(s>0){
			d = m - (s * a);
			if(d!=0 && s%d==0) ans.push_back(s);
			s -= 1;
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(int i = 0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
