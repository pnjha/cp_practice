#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int>p1, pair<int,int>p2){

	if(p1.first<p2.first)
		return true;

	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	// long long int clk = clock();

	int n,x,min_val = INT_MAX;
	cin>>n>>x;

	// unordered_map<int,int> present;
	vector<pair<int,int>> arr(n);

	for(int i = 0;i<arr.size();i++){
		cin>>arr[i].first;
		arr[i].second = i;
		// present[arr[i].first] = i;
		if(arr[i].first<min_val)
			min_val = arr[i].first;
	}

	bool flag = false;
	int a=-1,b=-1,c=-1;
	int j=0,k=0;

	sort(arr.begin(),arr.end(),cmp);

	for(int i = 0;i<arr.size();i++){
		
		j = i+1;
		k = arr.size()-1;

		while(j<k){

			if((arr[i].first + arr[j].first + arr[k].first) == x){
				a = arr[i].second+1;
				b = arr[j].second+1;
				c = arr[k].second+1;
				flag = true;
				break;
			}else if((arr[i].first + arr[j].first + arr[k].first) < x){
				j++;
			}else{
				k--;
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

	// cout<<clock() - clk<<"\n";

	return 0;
}
