#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,m = 5;
	cin>>n;

	int count = 0;

	while(int(n/m)>0){
		// cout<<(n/m)<<"\n";
		count += floor(n/m);
		m *= 5;
	}

	cout<<count<<"\n";

	return 0;
}
