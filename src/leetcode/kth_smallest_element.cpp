#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int left, int right){

	int pivot = right, i = left-1, j = left;

	for(;j<right;j++){

		if(arr[j] <= arr[pivot]){
			i++;
			swap(arr[j],arr[i]);
		}
	}

	i++;
	swap(arr[i],arr[pivot]);

	return i;
}

int quick_select(vector<int>& arr, int left, int right, int k){

	// cout<<left<<" "<<right<<" "<<k<<" \n";

	if(k >= 0 && k < (right - left + 1)){

		int pivot = partition(arr,left,right);
		
		if((pivot - left) == k){
			return arr[pivot];
		}else if(k < (pivot-left)){
			return quick_select(arr,left,pivot-1,k);
		}else{
			return quick_select(arr,pivot+1,right,k-pivot+left-1);
		}
	}

	return INT_MAX;
}

int main(){

	vector<int> arr = {3,2,5,4,1};
	int k = 0;

	cout<<quick_select(arr,0,arr.size()-1,k)<<"\n";

	return 0;
}