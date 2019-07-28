#include<bits/stdc++.h>

using namespace std;

int main(){

	int num;

	cout<<"Enter your number: ";
	cin>>num;
	cout<<"Set bit are: "<<__builtin_popcount(num)<<"\n";

	int counter = 0;

	while(num){
		if(num&1)
			counter++;
		num = num >> 1;
	}

	cout<<counter<<"\n";

	return 0;
}