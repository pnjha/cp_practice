// https://cses.fi/problemset/task/1621
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,temp;
	cin>>n;

	// long long int cnt = 0;

	// unordered_map<long long int,bool> table;
	vector<long long int > v(n); 

	for(int i = 0;i<n;i++){
		cin>>v[i];
		// cin>>temp;
		// if(table.find(temp)==table.end()){
		// 	cnt++;
		// 	table[temp] = true;
		// }
	}

	set<int> s{v.begin(),v.end()};
	cout<<s.size()<<"\n";
	// cout<<cnt<<"\n";

	return 0;
}
