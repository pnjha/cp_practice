#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r);
void merge_sort(vector<int>& arr, int l, int r);

void merge_sort(vector<int>& arr, int l, int r){
	if(l<r){
		int mid = l + (r-l)/2;

		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

void merge(vector<int>& arr, int l, int mid, int r){
	vector<int> temp;
	int i = l, j = mid+1;

	while(i<=mid && j<=r){
		if(arr[i]<arr[j]) temp.push_back(arr[i++]);
		else temp.push_back(arr[j++]);
	}

	while(i<=mid) temp.push_back(arr[i++]);
	while(j<=r) temp.push_back(arr[j++]);

	for(int i = l;i<=r;i++) arr[i] = temp[i-l];
}

int main(){

	vector<int> arr = {2,1,4,7,3,5};
	int n = arr.size();

	merge_sort(arr,0,n-1);

	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	return 0;
}
