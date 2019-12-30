// http://m1.codeforces.com/contest/1279/problem/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	freopen("input.txt","r",stdin);

	ll t,n,m,ans=0,seen=0,max_index=0;
	cin>>t;

	vector<ll> s,r,psum;
	unordered_map<int,int> index;

	while(t--){

		cin>>n>>m;
		s.clear(),s.resize(n);
		r.clear(),r.resize(m);
		index.clear();

		for(int i = 0;i<n;i++){
			cin>>s[i];
			index[s[i]] = i;
		}
		
		for(int i = 0;i<m;i++){
			cin>>r[i];
		}
	
		ans=0,max_index=0;

		for(int i = 0;i<m;i++){
			if(index[r[i]]>max_index){
				max_index = index[r[i]];
				ans += 2*(index[r[i]]-i) + 1;
			}else{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}	

	return 0;
}
