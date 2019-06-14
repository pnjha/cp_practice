#include<bits/stdc++.h>

using namespace std;

//Given a list of integer return the largest product that can 
//be made by multiplying any k integers

int maxProduct(vector<int>arr,int k){

	sort(arr.begin(),arr.end());

	int pindex = -1,nindex = 0,ans = 1;

	for(int i = 0;i<arr.size();i++){
		if(arr[i]>0){
			pindex = i;
			break;
		}
	}

	if(pindex == -1){
		if(k%2==0){
			for(int i = 0;i<k;i++)
				ans *= arr[i];
			return ans;
		}else{
			int i=arr.size()-1;
			while(k--){
				ans *= arr[i];
				i--;
			}
			return ans;
		}
	}else if(pindex == 0){
		int i=arr.size()-1;
		while(k--){
			ans *= arr[i];
			i--;
		}
		return ans;
	}

	int l=0,r = arr.size()-1;

	// cout<<(k)<<"\n";

	if((int)(arr.size() - pindex - k)<0&&
		(arr.size() - pindex - k)%2 == 1){

		l = pindex-1,r = pindex;

		while(k){
			
			if(arr[l]*(-1)<arr[r]){
				ans *= arr[l];
				l--;
				k--;
			}else{
				ans *= arr[r];
				r++;
				k--;
			}
		}
		return ans;
	}

	while(k){

		if(k==1){
			ans *= arr[r];
			// cout<<"here\n";
			return ans;
		}

		if(l+1<pindex){
			if(arr[l]*arr[l+1]>arr[r]*arr[r-1]){
				ans *= arr[l]*arr[l+1];
				l += 2;
			}else{
				ans *= arr[r]*arr[r-1];
				r -= 2;
			}
			k -= 2;
		}else{
			ans *= arr[r];
			k--;
			r--;
		}

	}
	return ans;
}

int main(){

	vector<int> arr;
	int k = 4;
	arr.push_back(-10);
	arr.push_back(-10);
	arr.push_back(5);
	arr.push_back(200);

	cout<<maxProduct(arr,k)<<"\n";

	return 0;
}	