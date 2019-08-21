// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,pair<int,int>>p1 , pair<int,pair<int,int>>p2){
	if(p1.second.second < p2.second.second)
		return true;
	return false;
}

void merge(vector<pair<int,pair<int,int>>>& arr, int left, int mid ,int right){

	int i = left, j = mid+1, cnt = 0, k = 0;

	while(i<=mid){
		while(j<=right && (arr[i].first>arr[j].first)){
			cnt++;
			j++;
		}
		arr[i].second.first += cnt;
		i++;
	}

	i = left;
	j = mid+1;

	vector<pair<int,pair<int,int>>> res((right - left + 1));

	while(i<=mid && j<=right && k<res.size()){

		if(arr[i].first < arr[j].first){
			res[k++] = arr[i++];
		}else{
			res[k++] = arr[j++];	
		}
	}

	while(i<=mid && k<res.size()){
		res[k++] = arr[i++];
	}

	while(j<=right && k<res.size()){
		res[k++] = arr[j++];
	}

	for(int i = 0;i<res.size();i++){
		arr[left + i] = res[i];
	}

} 

void merge_sort(vector<pair<int,pair<int,int>>>& arr, int left, int right){

	// cout<<left<<" "<<right<<"\n";

	int mid = 0;

	if(left<right){

		mid = left + (right - left)/2;

		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	
	}
}

int main(){

	// val, count, index

	vector<pair<int,pair<int,int>>> arr = {{5,{0,0}},{2,{0,1}},{6,{0,2}},{1,{0,3}},{2,{0,4}},{4,{0,5}},{1,{0,6}},{3,{0,7}}};

	int n = arr.size();

	merge_sort(arr,0,n-1);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i].first<<" ";

	cout<<"\n";

	sort(arr.begin(), arr.end(),cmp);

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i].second.first<<" ";

	cout<<"\n";	

	return 0;
}