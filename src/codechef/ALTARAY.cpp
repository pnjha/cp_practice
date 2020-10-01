#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,n;
	cin>>t;

	vector<int> arr;
	vector<int> ans;

	while(t--){

		cin>>n;

		arr.clear();
		ans.clear();

		arr.resize(n);
		ans.resize(n);

		for(int i = 0;i<arr.size();i++)
			cin>>arr[i];

		for(int i = arr.size()-1;i>=0;i--){
			if(i == arr.size()-1)
				ans[i] = 1;
			else{
				if((arr[i]>0 && arr[i+1]<0) || (arr[i]<0 && arr[i+1]>0)){
					ans[i] = ans[i+1] + 1;
				}else{
					ans[i] = 1;
				}
			}
		}

		for(int i = 0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}

	return 0;
}
