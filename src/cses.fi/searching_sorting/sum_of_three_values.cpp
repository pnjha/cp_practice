#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,x;
	cin>>n>>x;

	unordered_map<int,int> present;
	vector<int> arr(n);

	for(int i = 0;i<arr.size();i++){
		cin>>arr[i];
		present[arr[i]] = i;
	}

	bool flag = false;
	int a=-1,b=-1,c=-1;

	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<arr.size();j++){
			if(i!=j){
				if(present.find(x - (arr[i]+arr[j]))!=present.end()&&present[x - (arr[i]+arr[j])]!=i&&present[x - (arr[i]+arr[j])]!=j){
					a = arr[i];
					b = arr[j];
					c = x - (arr[i]+arr[j]);
					flag = true;
					break;
				}
			}
		}
		if(flag)
			break;
	}


	if(flag){
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}else{
		cout<<"IMPOSSIBLE\n";
	}

	return 0;
}
