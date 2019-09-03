// https://cses.fi/problemset/task/1628

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	ll n,x,temp;
	ll cnt = 0;
	cin>>n>>x;

	if(n == 1){
		cin>>temp;
		if(temp==x)
			cout<<"1\n";
		else
			cout<<"0\n";
		return 0;
	}

	
	vector<ll> set1,set2;

	for(int i = 0;i<n;i++){
		cin>>temp;

		if(temp>x)
			continue;

		if(i%2==0)
			set1.push_back(temp);
		else
			set2.push_back(temp);
	}

	map<ll,int> ump;

	for(int i = 0;i<(1<<set1.size());i++){
		temp = 0;
		// cout<<i<<"\n";
		int j = 0;
		for(j = 0;j<set1.size();j++){
			if(i&1<<j){
				temp+= set1[j];
			}
			if(temp>x)
				break;
		}
		if(j == set1.size())
			ump[temp]++;
	}

	// for(auto itr = ump.begin();itr!=ump.end();itr++)
	// 	cout<<itr->first<<" "<<itr->second<<"\n";


	for(int i = 0;i<(1<<set2.size());i++){
		
		temp = 0;
		int j = 0;
		for(j = 0;j<set2.size();j++){
		
			if(i&1<<j){
		
				temp += set2[j];
		
			}
			if(temp>x)
				break;
		}
		if(j == set2.size()){

			if(ump.find(x-temp)!=ump.end()){
				cnt += ump[x-temp];
			}
		}
	}	

	cout<<cnt<<"\n";

	return 0;
}
