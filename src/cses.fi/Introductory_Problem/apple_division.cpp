#include<bits/stdc++.h>

using namespace std;

long long int diff = INT_MAX;

void dfs(vector<long long int> arr, long long int left, long long int right, long long int index){

	if(index == arr.size()){
		if(abs(left-right)<diff)
			diff = abs(left-right);
		return;
	}

	dfs(arr,left+arr[index],right,index+1);
	dfs(arr,left,right+arr[index],index+1);	

}

int main(){

	ios_base::sync_with_stdio(false);

	diff = INT_MAX;

	long long int n;
	cin>>n;

	vector<long long int> arr(n,0);

	for(long long int i = 0;i<n;i++){
		cin>>arr[i];
	}

	long long int left = 0,right = 0;

	if(n == 2)
		diff = abs(arr[0] - arr[1]);

	else{

		dfs(arr,left+arr[0],right,1);
		dfs(arr,left,right+arr[0],1);
	}

	cout<<diff<<"\n";

	return 0;
}
