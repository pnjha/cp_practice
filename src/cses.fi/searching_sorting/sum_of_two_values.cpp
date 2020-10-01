// https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	// long long int clk = clock();

	int n,k;
	cin>>n>>k;

	vector<pair<int,int>> arr(n);
	
	for(int i = 0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(),arr.end());

	int i=0,j=n-1;

	int a=-1,b;

	while(i<j){

		if((arr[i].first + arr[j].first) == k){

			a = arr[i].second+1;
			b = arr[j].second+1;
			break;
		
		}else if((arr[i].first + arr[j].first) < k){

			i++;

		}else{
			j--;
		}

	}

	if(a==-1){
		cout<<"IMPOSSIBLE\n";
	}else{
		cout<<a<<" "<<b<<"\n";
	}

	// cout<<clock() - clk<<"\n";

	return 0;
}
