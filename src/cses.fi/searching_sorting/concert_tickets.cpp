// https://cses.fi/problemset/task/1091
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	// ios_base::sync_with_stdio(NULL);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int n,m,temp,ans = -1,index = -1;
	cin>>n>>m;

	multiset<ll,greater<ll>> tickets;
	
	for(int i = 0;i<n;i++){
		cin>>temp;
		tickets.insert(temp);
	}

	for(auto x:tickets){
		cout<<x<<" ";
	}cout<<"\n";

	for(int i = 0;i<m;i++){

		cin>>temp;
				 
		auto x = tickets.lower_bound(temp);

		if (x == tickets.end())
			cout << "-1\n";
	    else{
	      cout << *x << endl;
	      tickets.erase(x);
	    }
	}
	return 0;
}
