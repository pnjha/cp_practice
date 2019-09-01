#include<bits/stdc++.h>

using namespace std;

void longest_increasing_subsequence(vector<int>& arr){

	int lis_length = 0, last_ptr = 0;
	vector<int> parent(arr.size(),-1);
	vector<pair<int,int>> lis(arr.size()+1);
	vector<int> seq;

	for(int i = 0;i<arr.size();i++){

		int left = 1, right = lis_length, mid = 0;

		while(left<=right){
	
			mid = left + (right - left)/2;
	
			if(lis[mid].first < arr[i])
				left = mid+1;
	
			else
				right = mid-1;
		}

		lis[left] = {arr[i],i};
		// if(left>0)
			parent[i] = lis[left-1].second;
		// else
		// 	parent[i] = lis[left].second;
	}

	int k = lis[lis_length].second;

	for(int i = length-1;i>=0;i--){
		seq[i] = arr[k];
		k = parent[k];
	}

	for(int i = 0;i<seq.size();i++)
		cout<<seq[i]<<" ";
	cout<<"\n";
}

int main(){

	vector<int> arr = {3,4,5,6,7,8,9,1,5,2,6,4,9,10,7};

	longest_increasing_subsequence(arr);

	return 0;
}


// ///////////////////////////////////////////////////////////////////////////////////


// public static void LIS(int X[]){

// 	int parent[]= new int[X.length]; //Tracking the predecessors/parents of elements of each subsequence.
// 	int increasingSub[]= new int[X.length + 1]; //Tracking ends of each increasing subsequence.
// 	int length = 0; //Length of longest subsequence.
	
// 	for(int i=0; i<X.length; i++)
// 	{
// 		//Binary search
// 		int low = 1;
// 		int high = length;
// 		while(low <= high)
// 		{
// 			int mid = (int) Math.ceil((low + high)/2);
			
// 			if(X[increasingSub[mid]] < X[i])
// 				low = mid + 1;
// 			else
// 				high = mid - 1;
// 		}
		
// 		int pos = low;
// 		//update parent/previous element for LIS
// 		parent[i] = increasingSub[pos-1];
// 		//Replace or append
// 		increasingSub[pos] =  i;
		
// 		//Update the length of the longest subsequence.
// 		if(pos > length)
// 			length=pos;
// 	}
	
// 	//Generate LIS by traversing parent array
// 	int LIS[] = new int[length];
// 	int k 	= increasingSub[length];
// 	for(int j=length-1; j>=0; j--)
// 	{
// 		LIS[j] =  X[k];
// 		k = parent[k];
// 	}
	
	
// 	for(int i=0; i<length; i++)
// 	{
// 		System.out.println(LIS[i]);
// 	}		
// }