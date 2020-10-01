#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int>p1,pair<int,int>p2){

		if(p1.first < p2.first){

			return true;
		}else{
			return false;
		}
	// }
	return false;
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;

	vector<pair<int,int>> arr(n);

	for(int i = 0;i<n;i++)
		cin>>arr[i].first>>arr[i].second;

	sort(arr.begin(),arr.end());

	long long int reward = 0;
	long long int time = 0;

	for(int i = 0;i<n;i++){

		// cout<<arr[i].first<<" "<<arr[i].second<<"\n";

		time += arr[i].first;

		reward += arr[i].second - time;
	
		// cout<<time<<" "<<reward<<" "<<arr[i].second<<"\n";
	}

	cout<<reward<<"\n";

	return 0;
}
