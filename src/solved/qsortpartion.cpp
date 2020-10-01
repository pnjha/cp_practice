#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int l,int r){

	int pivot = r-1;

	int i = l-1,j = l,temp = 0;

	for(j = l;j<r-1;j++){
		if(arr[j]<arr[pivot]){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; 
		}
	}

	i++;

	temp = arr[i];
	arr[i] = arr[pivot];
	arr[pivot] = temp;

	return i;
}

void quickSort(int arr[], int l,int r){
	
	if(l<r){

		int mid = partition(arr,l,r);

		quickSort(arr,l,mid);
		quickSort(arr,mid+1,r);
	}
}


int main(){

	int arr[10] = {66,77,10,5,8,7,1,3,45,9};

	quickSort(arr,0,10);

	for(int i = 0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}