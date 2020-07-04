// https://www.codechef.com/JUNE20B/problems/COVDSMPL
#include<bits/stdc++.h>
using namespace std;

void update_arr(vector<vector<int>>& arr,unordered_map<int,int> row,unordered_map<int,int> col){
	for(auto x: row){
		if(x.second == 0){
			for(int i = 0;i<arr.size();i++){
				arr[x.first][i] = 0;
			}
		}else if(x.second == arr.size()){
			for(int i = 0;i<arr.size();i++){
				arr[x.first][i] = 1;
			}
		}
	}
	for(auto x: col){
		if(x.second == 0){
			for(int i = 0;i<arr.size();i++){
				arr[i][x.first] = 0;
			}
		}else if(x.second == arr.size()){
			for(int i = 0;i<arr.size();i++){
				arr[i][x.first] = 1;
			}	
		}
	}
}

int main(){

	// freopen("input.txt","r",stdin);
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	cin>>t;

	while(t--){

		int n,p,x;
		cin>>n>>p;

		vector<vector<int>> arr(n,vector<int>(n,-1));
		unordered_map<int,int> row;
		unordered_map<int,int> col;

		for(int i = 0;i<=n-2;i++){
			for(int j = 0;j<=n-2;j++){
				cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<"\n";
                cout.flush();
				cin>>x;
				if(x == -1) return 0;
				if(x == 4){
					for(int a = i;a<=i+1;a++){
						for(int b = j;b<=j+1;b++){
							arr[a][b] = 1;
						}	
					}
				}
			}
		}	

		for(int i = 0;i<n-1;i++){
			for(int j = 0;j<n-1;j++){
				if(arr[i][j]==-1 && arr[i][j+1]==-1){					
					cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<"\n";
					cin>>x;
					if(x == -1) return 0;
					if(x == 2){
						arr[i][j] = 1;
						arr[i][j+1] = 1;
						j++;
					}else if(x == 0){
						j++;
					}
				}
			}
		}
		
		for(int i = 0;i<n;i++){
			cout<<"1 "<<i+1<<" "<<1<<" "<<i+1<<" "<<n<<"\n";
			cin>>x;
			if(x == -1) return 0;
			if(x == 0) row[i] = 0;
			else if(x == n) row[i] = n;
		}

		for(int i = 0;i<n;i++){
			cout<<"1 "<<1<<" "<<i+1<<" "<<n<<" "<<i+1<<"\n";
			cin>>x;
			if(x == -1) return 0;
			if(x == 0) col[i] = 0;
			else if(x == n) col[i] = n;
		}

		update_arr(arr,row,col);

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(arr[i][j] == -1){
					cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<"\n";
					cin>>x;
					if(x == -1) return 0;
					arr[i][j] = x;
				}
			}
		}

		cout<<"2\n";
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}

		cin>>x;
		if(x == -1) return 0;
	}

	return 0;
}