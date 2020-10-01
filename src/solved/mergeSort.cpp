#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr,int left,int mid,int right){

	int i = 0,j = 0,k = left;
	vector<int> t1;
	vector<int> t2;

	for(int i = left;i<=mid;i++){
		cout<<arr[i]<<" ";
		t1.push_back(arr[i]);
	}

	cout<<"\t";

	for(int j = mid+1;j<=right;j++){
		cout<<arr[j]<<" ";
		t2.push_back(arr[j]);
	}

	cout<<"\n";


	while(i<t1.size()&&j<t2.size()){
		
		if(t1[i]<=t2[j]){

			arr[k] = t1[i];
			i++;
			k++;
		}else{
			arr[k] = t2[j];
			j++;
			k++;
		}
	}

	while(i<t1.size()){

		arr[k] = t1[i];
		i++;
		k++;
	}

	while(j<t2.size()){
		
		arr[k] = t2[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr,int left,int right){

	int mid;

	if(left<right){

		mid = left+(right-left)/2;
		cout<<"First left: "<<left<<" mid: "<<mid<<" right: "<<right<<"\n";
		mergeSort(arr,left,mid);
		cout<<"Second left: "<<left<<" mid: "<<mid<<" right: "<<right<<"\n";
		mergeSort(arr,mid+1,right);

		merge(arr,left,mid,right);

	}

}

int main(){

	vector<int> arr;

	arr.push_back(1);
	arr.push_back(20);
	arr.push_back(6);
	arr.push_back(4);
	arr.push_back(5);

	mergeSort(arr,0,arr.size()-1);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";


	return 0;
}
