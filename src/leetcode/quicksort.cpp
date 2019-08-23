#include<bits/stdc++.h>

using namespace std;

void print_vec(vector<int>& arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int partition_arr(vector<int>& arr, int left, int right){

	int pivot = right, i = left-1, j = left;

	for(;j<right;j++){

		if(arr[j] <= arr[pivot]){
			i++;
			swap(arr[i],arr[j]);
		}
	}

	i++;

	swap(arr[i],arr[pivot]);

	return i;
}

void quicksort(vector<int>& arr, int left, int right){

	if(left<right){

		print_vec(arr);

		int pivot = partition_arr(arr,left,right);

		quicksort(arr,left,pivot-1);
		quicksort(arr,pivot+1,right);
	}
}

int main(){

	vector<int> arr = {3,4,1,2,7,5};

	quicksort(arr,0,arr.size()-1);

	print_vec(arr);

	return 0;
}
