#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){

	cout<<gcd(10,6)<<"\n";

	return 0;
}
