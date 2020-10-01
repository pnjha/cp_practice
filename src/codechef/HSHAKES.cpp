#include<bits/stdc++.h>
#define int long long 
using namespace std;

int min_smog(vector<int>& arr){

	int n = arr.size();

	if(n == 1)
		return 0;

	priority_queue<int, vector<int>, greater<int>>p = {arr.begin(),arr.end()};

	long long cost = 0, a,b,c;

	while(!p.empty()){

		a = p.top();
		p.pop();

		if(p.empty())
			break;

		b = p.top();
		p.pop();

		c = a + b;
		cost += a * b;

		p.push(c);
	}

	return cost;
}

int32_t main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	int n;
	vector<int> arr;
	
	while(t--){
			
		cin>>n;

		arr.clear();
		arr.resize(n,0);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<min_smog(arr)<<"\n";
	}

	return 0;
}
