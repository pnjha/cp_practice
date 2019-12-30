// https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,k;

	cin>>n>>m>>k;

	vector<int> req_size(n);
	vector<int> room_size(m);

	for(int i = 0;i<req_size.size();i++)
		cin>>req_size[i];

	for(int i = 0;i<room_size.size();i++)
		cin>>room_size[i];

	sort(req_size.begin(),req_size.end());
	sort(room_size.begin(),room_size.end());

	int cnt = 0;

	for(int i = req_size.size()-1,j = room_size.size()-1;j>=0&&i>=0;){

		if(abs(req_size[i]-room_size[j])<=k){
			cnt++;
			j--;
			i--;
		}else{

			if(req_size[i] > room_size[j])
				i--;
			else
				j--;
		}
	}

	cout<<cnt<<"\n";

	return 0;
}
