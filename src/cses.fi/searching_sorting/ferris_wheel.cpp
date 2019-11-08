// https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	cin>>n>>k;

	vector<long long int> arr(n,0);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	int cnt = 0;

	sort(arr.begin(),arr.end());

	for(int i = 0,j = arr.size()-1;i<=j;){

		if(i == j){
			if(arr[i]!=-1)
				cnt++;
			break;
		}else{

			if(arr[i]+arr[j]<=k){
				cnt++;
				arr[i] = -1;
				arr[j] = -1;
				i++;
				j--;
			}else{
				if(arr[i]>arr[j]){
					cnt++;
					arr[i] = -1;
					i++;
				}else{
					cnt++;
					arr[j] = -1;
					j--;
				}
			}
		}

	}

	cout<<cnt<<"\n";

	return 0;
}
