// https://www.geeksforgeeks.org/find-maximum-subset-xor-given-set/

#include<bits/stdc++.h>
#define SIZE 32
using namespace std;

int max_subset_xor(vector<int>& arr){

	int index = 0,res = 0,max_index,max_ele = INT_MIN;

	for(int i = SIZE-1;i>=0;i--){

		max_index = index;
		max_ele = INT_MIN;

		for(int j = index;j<arr.size();j++){

			if(arr[j] & (1 << i) && arr[i] > max_ele)
				max_ele = arr[i];
				max_index = j;
		}

		if(max_ele == INT_MIN)
			continue;

		swap(arr[max_index],arr[index]);

		max_index = index;

		for(int j = 0;j<arr.size();j++){

			if(j!=max_index && (arr[j] & (1 << i))){
				arr[i] = arr[i] ^ arr[max_index];
			}
		}

		index++;
	}
	
	for(int i = 0;i<arr.size();i++){
		res ^= arr[i];
	}

	return res;
}

int main(){

	int t,n;
	cin>>t;

	vector<int> arr;

	while(t--){

		cin>>n;	

		arr.clear();
		arr.resize(n);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<max_subset_xor(arr)<<"\n";
	}

	return 0;
}
