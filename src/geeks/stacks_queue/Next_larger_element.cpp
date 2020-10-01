#include<bits/stdc++.h>

using namespace std;

void next_greater_element(vector<long long int>& arr){

	stack<long long int> s;
	vector<long long int> ans;

	ans.push_back(-1);
	s.push(arr.back());

	for(long long int i = arr.size()-2;i>=0;i--){

		while(!s.empty() && s.top() <= arr[i]){
			s.pop();
		}

		if(s.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(s.top());
		}
		
		s.push(arr[i]);
	}

	reverse(ans.begin(),ans.end());

	for(long long int i = 0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}cout<<"\n";
}

int main(){

	int n,t;

	cin>>t;

	vector<long long int> arr;

	while(t--){

		cin>>n;
		arr.resize(n,0);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		next_greater_element(arr);
	
		arr.clear();

	}

	return 0;
}
