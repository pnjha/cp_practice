// https://codeforces.com/contest/1234/problem/D

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	char v;

	cin>>str;

	int n,a,b,c,cnt = 0;
	cin>>n;

	vector<set<int>> arr(26);

	for(int i = 0;i<str.length();i++){
		arr[str[i]-'a'].insert(i);
	}

	for(int i = 0;i<n;i++){

		cin>>a;

		if(a == 1){

			cin>>b>>v;

			b--;

			arr[str[b]-'a'].erase(b);
			str[b] = v;
			arr[str[b]-'a'].insert(b);

		}else{

			cnt = 0;

			cin>>b>>c;

			--b, --c;

			for(int i = 0;i<arr.size();i++){

				auto x = arr[i].lower_bound(b);
				if (x != arr[i].end() && *x <= c)
					cnt++;
			}

			cout<<cnt<<"\n";
		}
	}

	return 0;
}