// https://hack.codingblocks.com/practice/p/366/463

#include<bits/stdc++.h>

using namespace std;

int main(){

	vector<int> arr = {1,2,3,5,6,1,2,3};

	int x = arr[0];

	for(int i = 1;i<arr.size();i++){
		x = x ^ arr[i];
	}

	int temp = x,index = 0;

	while(temp){
		if(temp&1){
			break;
		}
		temp >>= 1;
		index++;
	}

	int b = 0,c=0;

	for(int i = 0;i<arr.size();i++){

		if(arr[i]&(1<<index)){
			b ^= arr[i];
		}
	}

	cout<<b<<" "<<(x^b)<<"\n";

	return 0;
}
