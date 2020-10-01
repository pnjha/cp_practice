#include<bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int key){
	int l = 0, r = arr.size()-1, mid = 0;
	while(l<=r){
		mid = l + (r-l)/2;
		if(arr[mid] == key) return mid;
		if(arr[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int main(){

	vector<int> a = {1,4,7,13,20,65};
	int ans = binary_search(a, 1);
	cout<<"index: "<<ans<<"\n";

	return 0;
}
