#include<bits/stdc++.h>

using namespace std;

int _time_to_rot(vector<vector<int>>& arr,int nrcnt,int rcnt){

	vector<vector<int>> temp;
	bool flag = true;
	int olv_val = nrcnt,cnt = 0;

	while(nrcnt>0 && flag){

		cnt++;
		olv_val = nrcnt;
		temp = arr;

		for(int i = 0;i<arr.size();i++){
			for(int j = 0;j<arr[i].size();j++){

				if(arr[i][j] == 2){

					if(i-1>=0 && arr[i-1][j] == 1){
						nrcnt--;
						temp[i-1][j] = 2;
					}
					if(j-1>=0 && arr[i][j-1] == 1){
						nrcnt--;
						temp[i][j-1] = 2;
					}
					if(i+1<arr.size() && arr[i+1][j] == 1){
						nrcnt--;
						temp[i+1][j] = 2;
					}
					if(j+1<arr[i].size() && arr[i][j+1] == 1){
						nrcnt--;
						temp[i][j+1] = 2;
					}
				}
			}
		}		

		if(olv_val == nrcnt){
			flag = false;
			break;
		}

		arr = temp;
	}

	if(!flag)
		return -1;

	return cnt;
}

int time_to_rot(vector<vector<int>>& arr){

	int depth = 0;

	queue<pair<int,pair<int,int>>> q;

	pair<int,pair<int,int>> p;

	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<arr[i].size();j++){
			if(arr[i][j]==2)
				q.push({0,{i,j}});
		}
	}

	int i,j;

	while(!q.empty()){

		p = q.front();
		q.pop();

		if(depth < p.first)
			depth = p.first;

		i = p.second.first;
		j = p.second.second;

		if(i-1>=0 && arr[i-1][j] == 1){
			arr[i-1][j] = 2;
			q.push({depth+1,{i-1,j}});
		}
		if(j-1>=0 && arr[i][j-1] == 1){
			arr[i][j-1] = 2;
			q.push({depth+1,{i,j-1}});
		}
		if(i+1<arr.size() && arr[i+1][j] == 1){
			arr[i+1][j] = 2;
			q.push({depth+1,{i+1,j}});
		}
		if(j+1<arr[i].size() && arr[i][j+1] == 1){
			arr[i][j+1] = 2;
			q.push({depth+1,{i,j+1}});
		}
	}

	for(int i = 0;i<arr.size();i++){
		for(int j = 0;j<arr[i].size();j++){
			if(arr[i][j]==1)
				return -1;
		}
	}

	return depth;
}

int main(){

	int t,r,c, rcnt = 0, nrcnt = 0;

	cin>>t;

	vector<vector<int>> arr;

	while(t--){

		rcnt = 0;
		nrcnt = 0;

		cin>>r>>c;

		arr.resize(r,vector<int>(c,0));

		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				cin>>arr[i][j];
			}
		}

		cout<<time_to_rot(arr)<<"\n";
	}

	return 0;
}
