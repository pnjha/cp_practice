// https://codeforces.com/contest/1234/problem/B1

#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	ll n,k,a,b;

	cin>>n>>k;

	queue<ll> q;
	map<ll,bool> ump;

	for(int i = 0;i<n;i++){
		cin>>a;
		if(q.size()<k){
			if(ump[a]==false){
				ump[a] = true;
				q.push(a);
			}
		}else{
			if(ump[a]==false){
				b = q.front();
				q.pop();
				q.push(a);
				ump[a] = true;
				ump[b] = false;
			}
		}	
	}

	vector<ll> v;
	while(!q.empty()){
		v.push_back(q.front());
		q.pop();
	}

	reverse(v.begin(),v.end());

	cout<<v.size()<<"\n";

	for(int i = 0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";

	return 0;
}

