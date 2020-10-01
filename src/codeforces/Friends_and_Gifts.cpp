// http://m1.codeforces.com/contest/1283/problem/C
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin>>n;
	
	vector<ll> arr(n+1), empty,temp;
	map<int,int> temp_index, present; 
	
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=0) present[arr[i]] = 1;
		if(arr[i]==0) empty.push_back(i);
	}

	for(int i = 1;i<=n;i++){
		if(present[i]!=1){
			temp.push_back(i);
		}
	}

	int l = temp.size();

	// for(auto x:temp) cout<<x<<" ";
	// 	cout<<endl;

	for(int i = 0,j = 0;i<empty.size();i++){
		// cout<<i<<"\n";
		// cout<<j<<" "<<empty[i]<<" "<<temp[j]<<"\n";
		if(temp[j] == -1 || empty[i]==temp[j]){
			i--;
			j = (j+1)%l;
			// cout<<j<<"\n";
			continue;
		}else{
			arr[empty[i]] = temp[j];
			temp[j] = -1;
			j = (j+1)%l;
		}
	}

	for(int i = 1;i<arr.size();i++){
		cout<<arr[i]<<" ";
	} 
	cout<<"\n";

	return 0;
}
