#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){

	freopen("input.txt","r",stdin);

	ll t,subs,a,n,k;
	cin>>t;

	for(int l = 1;l<=t;l++){
		
		map<ll,vector<int>> emp;
		map<vector<int>,int> mp;
		vector<int> temp_s,tempx,tempy,r;

		int n,k;
		cin>>n>>k;

		for(int i=1;i<=n;i++){

			cin>>subs;

			temp_s.clear();

			for(int k=0;k<subs;k++){
				cin>>a;
				emp[i].push_back(a);
				temp_s.push_back(a);
			}

			sort(emp[i].begin(),emp[i].end());
            sort(temp_s.begin(),temp_s.end());

			mp[temp_s]++;
		}

		a = 0;
		ll ans = 0,b = 0;

		for(auto x : emp){
			
			r = x.second;
			b = 0;

			for(int i = 1;i<(1<<r.size());i++){
				tempx.clear();
				for(int j = 0;j<r.size();j++){
					if(i&1<<j){
						tempx.push_back(r[j]);
					}
				}
				b = b + mp[tempx];
			}
			// cout<<b<<"\n";
			ans = ans + (n - b);
		}

		cout <<"Case #" << l <<": "<<ans<<"\n";

	}
	return 0;
}