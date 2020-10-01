// https://www.codechef.com/LRNDSA03/problems/SAVKONO

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t,n,z,a;
	cin>>t;
	while(t--){

		cin>>n>>z;
		priority_queue<ll> pq;
		// pq.clear();
		for(int i = 0;i<n;i++){
			cin>>a;
			pq.push(a);
		}
		int cnt = 0;
		while(!pq.empty() && z>0){
			a = pq.top();
			z -= a;
			pq.pop();
			if(a/2>0)
				pq.push(a/2);
			cnt++;
		}
		if(z>0) cout<<"Evacuate\n";
		else cout<<cnt<<"\n";
	}	

	return 0;
}


/*
1
5 25
7 13 8 17 3
*/