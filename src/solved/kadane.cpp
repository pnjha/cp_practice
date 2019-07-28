#include<bits/stdc++.h>

using namespace std;

int maxSumSubArray(vector<int>arr){

	int max = 0,msf = INT_MIN;

	for(int i = 0;i<arr.size();i++){

		max += arr[i];

		if(max<0)
			max = 0;

		if(max>msf)
			msf = max;

	}
	return msf;
}

int main(){

	vector<int>arr;
	arr.push_back(0);
	arr.push_back(0);

	cout<<maxSumSubArray(arr)<<"\n";
	return 0;
}


  