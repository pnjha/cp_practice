#include<bits/stdc++.h>

using namespace std;

void minHeapify(vector<int> &arr,int index){

	int left = index*2+1;
	int right = index*2+2;
	int smallest = index,temp;

	if(left<arr.size()&&arr[left]<arr[index])
		smallest = left;
	if(right<arr.size()&&arr[right]<arr[smallest])
		smallest = right;

	if(smallest!=index){
		temp = arr[smallest];
		arr[smallest] = arr[index];
		arr[index] = temp;
		minHeapify(arr,smallest);
	}
}

void buildHeap(vector<int> &arr){
	for(int i = floor(arr.size()/2);i>=0;i--){
		minHeapify(arr,i);
	}
}

int extractMin(vector<int> &arr){
	int ans = arr[0];
	arr[0] = arr[arr.size()-1];
	arr.resize(arr.size()-1);
	minHeapify(arr,0);
	return ans;
}

void heapSort(vector<int> &arr){
	buildHeap(arr);
	int size = arr.size();
	vector<int> ans;
	for(int i = 0;i<size;i++){
		ans.push_back(extractMin(arr));
	}

	arr.clear();
	arr = ans;
	ans.clear();
}



void insert(vector<int> &arr,int value){
	
	int temp;

	arr.push_back(value);
	for(int i = arr.size()-1;i>=0;){
		if(arr[i]<arr[floor(i/2)]){
			temp = arr[i];
			arr[i] = arr[floor(i/2)];
			arr[floor(i/2)] = temp;
			i = floor(i/2);
		}else{
			break;
		}
	}
}

int main(){

	vector<int> arr;

	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(10);
	arr.push_back(8);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(6);

	buildHeap(arr);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	heapSort(arr);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	insert(arr,5);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	heapSort(arr);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	return 0;
}
