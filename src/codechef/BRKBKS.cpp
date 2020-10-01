// https://www.codechef.com/JAN20B/problems/BRKBKS
#include<bits/stdc++.h>

using namespace std;

int dfs(vector<int> arr, int l, int r, int s){
	// cout<<l<<" "<<r<<"\n";
	if(l>r) return 0;
	int left = l, right = r;
	int sum = 0;
	while(left<=r && sum+arr[left]<=s){
		sum += arr[left];
		left++;
	}
	// cout<<sum<<" "<<left<<"\n";
	if(left > r && sum>=s) return 1;
	int x = dfs(arr,left,r,s);
	sum = 0;
	while(right>=l && sum+arr[right]<=s){
		sum += arr[right];
		right--;
	}
	if(right < l && sum>=s) return 1;
	int y = dfs(arr,l,right,s);
	// cout<<l<<" "<<r<<" "<<x<<" "<<y<<"\n";
	return min(x,y)+1;
}

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t,s;

	cin>>t;
	while(t--){
		vector<int> arr(3,0);
		cin>>s;
		for(int i = 0;i<3;i++) cin>>arr[i];
		cout<<dfs(arr,0,2,s)<<"\n";
	}

	return 0;
}

/*
3
3 1 2 2
2 1 1 1
3 2 2 1
*/