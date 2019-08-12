#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	int cnt = 0,p;

	while(n){
		
		cnt++;
		p = n & (-n);	
		n = n - p;
	}

	cout<<cnt<<"\n";

	return 0;
}
