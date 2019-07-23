#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,temp = 0,ans = 0;
	cin>>n;

	for(int i = 1;i<n;i++){

		cin>>temp;
		ans = ans ^ temp ^ i;
	}

	cout<<(ans^n)<<"\n";

	return 0;
}
