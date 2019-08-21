// https://leetcode.com/problems/reverse-pairs/

#include<bits/stdc++.h>

using namespace std;

int _backup_merge_array(vector<int>& arr, int left, int mid, int right){

	cout<<left<<" "<<mid<<" "<<right<<" \n";

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	// vector<int> res;
	// int i = left, j = mid+1, inversions = 0;

	// while(i<=mid && j<=right){

	// 	if(arr[i]<arr[j])
	// 		res.push_back(arr[i++]);
	// 	else{	
	// 		if(arr[i] > 2 * arr[j]){
	// 			cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<"\n";
	// 			inversions += mid - i + 1;
	// 		}
	// 		res.push_back(arr[j++]);
	// 	}
	// }
	
	// while(i<=mid){
	// 	res.push_back(arr[i++]);
	// }

	// while(j<=right){
	// 	res.push_back(arr[j++]);
	// }



	vector<int> res(right - left + 1, 0);
	
	cout<<"res: "<<res.size()<<"\n";

	int i = mid, j = right, inversions = 0, k = res.size()-1;

	while(i>=left && j>mid && k>=0){
	
		cout<<"res vec: \n";
		for(int i = 0;i<res.size();i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";

		cout<<"1: "<<i<<" "<<j<<" "<<k<<"\n";
		if(arr[i] > arr[j]){
			cout<<"asfsdf\n";
			if(arr[i] > 2 * arr[j]){
				inversions++;				
			}
			res[k--] = arr[i--];
		}else{
			res[k--] = arr[j--];
		}
	}

	cout<<"res vec: \n";
		for(int i = 0;i<res.size();i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";


	while(i>=left && k>=0){
		cout<<"2: "<<i<<" "<<j<<" "<<k<<"\n";
		// cout<<k<<" :::1:\n";
		res[k--] = arr[i--];
		// cout<<k<<" :::2:\n";
	}

	cout<<"res vec: \n";
		for(int i = 0;i<res.size();i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";

	// cout<<"3: "<<k<<"\n";
	while(j>mid && k>=0){
		cout<<"3: "<<i<<" "<<j<<" "<<k<<"\n";
		res[k--] = arr[j--];
	}	
	cout<<"4: "<<k<<"\n";
	for(int i = 0;i<res.size();i++){
		cout<<res[i]<<" ";
		arr[left + i] = res[i];	
	}
	cout<<"\n";

	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	return inversions;
}

int merge_array(vector<int>& arr, int left, int mid, int right){

	vector<int> res(right - left + 1, 0);
	
	int i = mid, j = right, inversions = 0, k = res.size()-1;

	i = left;
	j = mid+1;

	while(i<=mid){
		
		while(j<=right && (long long int)arr[i] > (long long int)(2*(long long int)(arr[j])))
			j++;

		inversions += j - mid - 1;
		i++;
	}

	i = mid;
	j = right;

	while(i>=left && j>mid && k>=0){
	
		if(arr[i] > arr[j] || (long long int)arr[i] > (long long int)(2*(long long int)(arr[j]))){
			// if((long long int)arr[i] > (long long int)(2*(long long int)(arr[j]))){
			// 	inversions += j - mid;				
			// }
			res[k--] = arr[i--];
		}else{
			res[k--] = arr[j--];
		}
	}

	while(i>=left && k>=0){
		res[k--] = arr[i--];
	}
	while(j>mid && k>=0){
		res[k--] = arr[j--];
	}	

	for(int i = 0;i<res.size();i++){
		arr[left + i] = res[i];	
	}

	return inversions;
}

int mergesort(vector<int>& arr, int left, int right){

	int mid = 0,inversions=0;

	if(left<right){

		mid = left + (right - left)/2;
		
		inversions += mergesort(arr,left,mid);
		
		inversions += mergesort(arr,mid+1,right);
		
		inversions += merge_array(arr,left,mid,right);
		
	}
	return inversions;
}

int main(){

	vector<int> arr = {1,3,2,3,1};
	int n = arr.size();

	cout<<mergesort(arr,0,n-1)<<"\n";

	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	return 0;
}
