#include<bits/stdc++.h>

using namespace std;

int get_sum_middle(vector<int>& a,vector<int>& b){

	int n = a.size();
	int la = 0,ra = n-1,lb = 0,rb = n-1;

	

	return 0;
}

int main(){

	int t,n;
	cin>>t;

	vector<int> a,b;

	while(t--){

		cin>>n;

		for(int i = 0;i<n;i++)
			cin>>a[i];
		for(int j = 0;j<n;j++)
			cin>>b[j];

		cout<<get_sum_middle(a,b)<<"\n";
	}

	return 0;
}
