#include<bits/stdc++.h>

using namespace std;

void merge_array(vector<int>& arr, int left, int mid, int right){

	vector<int> res;
	int i = start, j = 0, k = 0;

	while(i<mid && j<=right){

		if(arr[i]<arr[j])
			res.push_back(arr[i++]);
		else
			res.push_back(arr[j++]);
	}
	
	while(i<mid){
		res.push_back(arr[i++]);
	}

	while(j<=right){
		res.push_back(arr[j++]);
	}
	
	for(int i = left;i<=right;i++)
		arr[i] = res[i];	
}

void mergesort(vector<int>& arr, int left, int right){

	int mid = 0;

	if(left<right){

		mid = left + (right - left)/2;

		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge_array(arr,left,mid+1,right);
	}
}

int main(){

	vector<int> arr = {3,5,1,6,7};
	int n = arr.size();

	mergesort(arr,0,n-1);

	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	return 0;
}
