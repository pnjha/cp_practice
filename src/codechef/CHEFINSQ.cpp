// https://www.codechef.com/SEPT19B/problems/CHEFINSQ

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int meet_in_middle(vector<int>& arr, int k, int x){

	ll n = arr.size(),temp = 0;
	ll cnt = 0;

	if(n == 1){
		return 1;
	}

	
	vector<ll> set1,set2;

	for(int i = 0;i<n;i++){

		if(arr[i]>x){
			break;
		}

		if(i%2==0)
			set1.push_back(arr[i]);
		else
			set2.push_back(arr[i]);
	}

	//number, size of set, count
	map<ll,map<ll,ll>> ump;

	for(int i = 0;i<(1<<set1.size());i++){
		
		temp = 0;
		
		bool flag = true;
		int j = 0,c = 0;
		
		for(j = 0;j<set1.size();j++){
			if(i&1<<j){
				c++;
				temp+= set1[j];
			}
			if(temp>x||c>k){
				flag = false;
				break;
			}
		}
		if(flag){
			ump[temp][c]++;
		}
	}


	for(int i = 0;i<(1<<set2.size());i++){
		
		temp = 0;
		
		bool flag = true;
		int j = 0,c = 0;
		
		for(j = 0;j<set2.size();j++){
		
			if(i&1<<j){
		
				temp += set2[j];
				c++;
			}
			if(temp>x || c>k){
				flag = false;
				break;
			}
		}

		if(flag){
			if(ump.find(x-temp)!=ump.end()){
				if(ump[x-temp].find(k-c)!=ump[x-temp].end())
					cnt += ump[x-temp][k-c];
			}
		}
	}	

	return cnt;
}


int main(){

	int t,n,k,x;

	cin>>t;

	vector<int> arr;

	while(t--){

		cin>>n>>k;

		arr.clear();
		arr.resize(n);

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr.begin(),arr.end());

		x = 0;
		
		for(int i = 0;i<k;i++)
			x += arr[i];

		cout<<meet_in_middle(arr,k,x)<<"\n";
	}

	return 0;
}
