#include<bits/stdc++.h>

using namespace std;

int main(){

	int a = 30,b = 30,carry=0;

	while(b){

		carry = a&b;

		a = a^b;

		b = carry<<1;
	}


	cout<<a<<"\n";

	return 0;
}
