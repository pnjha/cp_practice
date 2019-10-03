// https://cses.fi/problemset/task/1161
//huffman coding

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ll rod_length, n, a, b,c;
	cin>>rod_length>>n;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for(int i = 0;i<n;i++){
		cin>>a;
		pq.push(a);
	} 

	ll ans = 0;

	while(pq.size()>1){

		b = pq.top();
		pq.pop();
		c = pq.top();
		pq.pop();
		pq.push(b+c);
		ans += b+c;
	}

	cout<<ans<<"\n";

	return 0;
}