#include<bits/stdc++.h>

using namespace std;

int getNum(vector<int>arr,int k){

	vector<int> bits(32,0);

	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<32;j++){

			if(arr[i]>>j&1)
				bits[j] = (bits[j]+1)%k;	
		}

	}

	int ans = 0;

	// reverse(bits.begin(),bits.end());

	for(int i = 0;i<bits.size();i++){

		if(bits[i]==1){
			ans |= 1<<i;
		}
	}

	return ans;
}

int main(){

	vector<int> arr{0,0,1,2,2,1,2,3,3};

	cout<<getNum(arr,2)<<"\n";

	return 0;
}