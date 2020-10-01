#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int l, int mid, int r);
int merge_sort(vector<int>& arr, int l, int r);

int merge_sort(vector<int>& arr, int l, int r){
	int c = 0;
	if(l<r){
		int mid = l + (r-l)/2;

		c += merge_sort(arr, l, mid);
		c += merge_sort(arr, mid+1, r);
		c += merge(arr, l, mid, r);
	}
	return c;
}

int merge(vector<int>& arr, int l, int mid, int r){
	vector<int> temp;
	int i = l, j = mid+1, c = 0;

	while(i<=mid && j<=r){
		if(arr[i]<arr[j]) temp.push_back(arr[i++]);
		else {
			c += (mid - i + 1);
			temp.push_back(arr[j++]);
		}
	}

	while(i<=mid) temp.push_back(arr[i++]);
	while(j<=r) temp.push_back(arr[j++]);

	for(int i = l;i<=r;i++) arr[i] = temp[i-l];
	return c;
}

int main(){

	vector<int> arr = {2,1,4,7,3,5};
	// vector<int> arr = {1,20,6,4,5};

	int n = arr.size();

	int c = merge_sort(arr,0,n-1);

	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	cout<<c<<"\n";

	return 0;
}
