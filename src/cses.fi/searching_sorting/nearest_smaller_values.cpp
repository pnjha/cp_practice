#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,j=0;
	cin>>n;

	bool flag = false;
	vector<int> arr(n);
	vector<int> ans(n);

	for(int i = 0;i<arr.size();i++)
		cin>>arr[i];

	ans[0] = 0;

	for(int i = 1;i<arr.size();i++){

		flag = false;

		if(arr[i]>arr[i-1]){
			ans[i] = i;
		}else{
			j = ans[i-1]-1;

			while(j>=0){

				if(arr[i]>arr[j]){
					flag = true;
					break;
				}else{
					j = ans[j]-1;
				}

			}
			if(flag)
				ans[i] = j+1;
			else
				ans[i] = 0;
		}

	}


	for(int i = 0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<"\n";

	return 0;
}
