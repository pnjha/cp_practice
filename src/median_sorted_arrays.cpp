#include<bits/stdc++.h>

using namespace std;

double get_median(vector<int> a,int start,int end){
	int size = end - start + 1;

	if(size%2==0){
		return 1.0*(a[start+size/2] + a[start+size/2-1])/2;
	}else{
		return a[start+size/2];
	}
}

double median_sorted_arrays(vector<int>& arr1,vector<int>& arr2){

	double median = 0.0;

	int start1 = 0,start2 = 0,end1 = arr1.size()-1, end2 = arr2.size()-1;
	double median1 = 0.0,median2 = 0.0;

	cout<<start1<<' '<<end1<<" "<<start2<<" "<<end2<<"\n";

	while(end1 - start1 >= 2 || end2 - start2 >= 2){
		
		median1 = get_median(arr1,start1,end1);
		median2 = get_median(arr2,start2,end2);
		
		cout<<"median1: "<<median1<<" median2: "<<median2<<"\n";

		if(median1 == median2)
			return median1;
		else if(median1 < median2){
			start1 = (int)((end1 + start1)/2);
			end2 = (int)((end2 + start2)/2);
		}else{
			end1 = (int)((end1 + start1)/2);
			start2 = (int)((end2 + start2)/2);
		}

		cout<<start1<<' '<<end1<<" "<<start2<<" "<<end2<<"\n";
	}


	cout<<arr1[start1]<<" "<<arr2[start2]<<" "<<arr1[end1]<<" "<<arr2[end2]<<" \n";
	if(start1 == end1){
		if(arr1[start1]<arr2[start2])
			return arr2[start2];
		else if(arr1[start1]>arr2[end2])
			return arr2[end2];
		else
			return arr1[start1];
	}else if(start2 == end2){
		if(arr1[start1]>arr2[start2])
			return arr1[start1];
		else if(arr2[start2]>arr1[end1])
			return arr1[end1];
		else
			return arr2[start2];
	}else{
		median = ceil(1.0*(max(arr1[start1],arr2[start2]) + min(arr1[end1],arr2[end2]))/2);	
	}
	
	

	return median;
}

int main(){

	int n,m;
	cin>>n>>m;

	vector<int> arr1(n,0);
	vector<int> arr2(m,0);

	for(int i = 0;i<n;i++){
		cin>>arr1[i];
		// cout<<"here1\n";
	}

	for(int i = 0;i<m;i++){
		cin>>arr2[i];
		// cout<<"here2\n";
	}

	cout<<median_sorted_arrays(arr1,arr2)<<"\n";

	return 0;
}
