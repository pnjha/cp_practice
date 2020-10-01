// http://m1.codeforces.com/contest/1279/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ll t,n,s,temp,q,r,ans=0,p,min_sum,l;
	vector<ll> arr;

	cin>>t;

	while(t--){
		cin>>n>>s;

		arr.clear();
		arr.resize(n,0);

		temp=0;
		
		for(int i = 0;i<n;i++){
			cin>>arr[i];
			temp += arr[i];
		} 

		if(temp<=s){
			cout<<"0\n";
			continue;
		}

		q=0,r=arr[0],l=arr[0];
		for(int i = 1;i<arr.size();i++){
			// cout<<q<<" "<<r<<"\n";
			if(l>s && (min(r,q)+arr[i])>s){
				p = i-1;
				min_sum = min(q,r);
				break;
			}
			r = min(r,q)+arr[i];
			q = l;
			l += arr[i];
		}
		// cout<<q<<" "<<r<<"\n";

		if(l == temp && (q<=s || r<=s)){
			min_sum = min(q,r);
			p=n-1;
		}
		// cout<<min_sum<<"\n";

		temp=0;
		for(int i = 0;i<=p;i++){
			temp += arr[i];
		}

		q = temp - min_sum;
		for(int i = 0;i<=p;i++){
			if(q == arr[i]){
				ans = i+1;
				break;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
