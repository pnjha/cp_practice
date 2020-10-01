#include<bits/stdc++.h>

using namespace std;

bool checkMajorirtyElement(vector<int>a,int x){

	int count = 0;

	for(int i = 0;i<a.size();i++){
		if(a[i]==x)
			count++;
	}

	if(count>floor(a.size()/2))
		return true;
	else
		return false;

}

int majorityElement(vector<int>a){

	int max_index = 0;
	int count = 1;

	for(int i = 1;i<a.size();i++){
		if(a[i]==a[max_index])
			count++;
		else
			count--;
		if(count==0){
			max_index = i;
			count = 1;
		}
	}

	if(checkMajorirtyElement(a,a[max_index]))
		return a[max_index];
	else
		return -1;
}


int main(){

	int arr[] = {1,1,2,3,1,2,2,2,2,2,2,2,2};

	vector<int> a(arr,arr+sizeof(arr)/sizeof(arr[0]));

	cout<<majorityElement(a)<<"\n";

	return 0;
}
