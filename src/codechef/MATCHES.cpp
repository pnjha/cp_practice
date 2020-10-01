// https://www.codechef.com/COOK110B/problems/MATCHES

#include<bits/stdc++.h>

using namespace std;

int main(){

	long long int t,a,b,c,d;

	vector<int> m = {6,2,5,5,4,5,6,3,7,6};

	cin>>t;

	while(t--){
		cin>>a>>b;

		d = 0;
		c = a + b;

		while(c){

			d += m[c%10];
			c = c/10;
		}

		cout<<d<<"\n";
	}

	return 0;
}
