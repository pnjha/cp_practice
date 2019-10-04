// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666c
// F(x, k) = min(F(i, k-1) + R(i+1, x))

#include<bits/stdc++.h>
#define SIZE 1007
using namespace std;

int debug = 0;

int R[SIZE][SIZE], F[SIZE][SIZE];

vector<int> arr;

int r(int left, int right){

	int max_cnt = 0;
	unordered_map<int,int> ump;

	for(int i = left;i<=right;i++){
		ump[arr[i]]++;
		if(ump[arr[i]]>max_cnt)
			max_cnt = ump[arr[i]];
	}

	R[left][right] = (right-left+1-max_cnt);

	return R[left][right];
}

int f(int x, int k, int p){

	if(debug)
		cout<<setw(p)<<"entering "<<x<<" "<<k<<" \n";

	if(k<0)
		return 0;

	if(F[x][k]!=-1){
		if(debug)
			cout<<setw(p)<<"exit "<<x<<" "<<k<<" "<<F[x][k]<<"\n";
		return F[x][k];
	}

	if(k==0){
		return (R[1][x]==-1)?r(1,x):R[1][x];		
	}

	int min_remv = INT_MAX;

	for(int i = 1;i<=x;i++){
		
		min_remv = min(min_remv, f(i,k-1,p+4)+((R[i+1][x]==-1)?r(i+1,x):R[i+1][x]));
	}

	F[x][k] = min_remv;
	
	if(debug)
		cout<<setw(p)<<"exit     "<<x<<" "<<k<<" "<<min_remv<<"\n";

	return min_remv;
}

int main(){

	freopen("input.txt","r",stdin);

	int t,n,k,cnt = 0,ans;

	cin>>t;

	for(int i = 1;i<=t;i++){

		cin>>n>>k;

		arr.clear();
		arr.resize(n+1);

		for(int i = 1;i<=n;i++){
			cin>>arr[i];
		}

		memset(R,-1,sizeof(R));
		memset(F,-1,sizeof(F));

		ans = f(n,k,2);

		if(debug){
	
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=k;j++){
					cout<<setw(10)<<F[i][j]<<" ";
				}cout<<"\n";
			}
	
			cout<<"\n\n";
	
			for(int i = 1;i<=n;i++)
				cout<<setw(3)<<arr[i]<<" ";
			cout<<"\n";
	
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					cout<<setw(3)<<R[i][j]<<" ";
				}cout<<"\n";
			}
		}

		cout <<"Case #" << i <<": "<<ans<<"\n";
	}

	return 0;
}



// void dfs(vector<int> arr, int index, int& step, int cnt){

// 	if(cnt == 1){
// 		return;
// 	}

// 	int temp1 = step,temp2 = step,g,h = step;

// 	for(int i = index;i<arr.size()-1;i++){

// 		if(arr[i]!=arr[i+1]){
// 			g = arr[i];
// 			arr[i] = arr[i+1];
// 			dfs(arr,i,++temp2,cnt-1);
// 			arr[i] = g;
// 		}
// 	}

// 	if(temp1 == step)
// 		step =temp2;
// 	else if(temp2 == step)
// 		step =temp1;
// 	else
// 		step = min(temp1,temp2);
// }

// int main(){

// 	freopen("input.txt","r",stdin);

// 	int t,n,k,cnt = 0,g;

// 	cin>>t;

// 	for(int i = 0;i<t;i++){

// 		cin>>n>>k;

// 		vector<int> arr(n);

// 		for(int i = 0;i<n;i++){
// 			cin>>arr[i];
// 		}

// 		for(int i = 1;i<n;i++){
// 			if(arr[i]!=arr[i-1]){
// 				cnt++;
// 			}
// 		}		

// 		cnt = cnt - k;
		
// 		if(cnt<=0)
// 			cnt = 0;

// 		int temp1 = 0,temp2 = 0,ans = 0;
// 		bool flag1 = false, flag2 = false;

// 		if(cnt>0){

// 			for(int i = 1;i<n-1;i++){
				
// 				if(arr[i]!=arr[i-1]){
// 					flag1 = true;
// 					g = arr[i];
// 					arr[i] = arr[i-1];
// 					dfs(arr,i,++temp1,cnt-1);
// 					arr[i] = g;
// 				}

// 				if(arr[i]!=arr[i+1]){
// 					g = arr[i];
// 					flag2 = true;
// 					arr[i] = arr[i+1];
// 					dfs(arr,i+1,++temp2,cnt-1);
// 					arr[i] = g;
// 				}

// 				if(flag1 || flag2)
// 					break;
// 			}
// 		}

// 		if(temp1 == ans)
// 			ans = temp2;
// 		else if(temp2 == ans)
// 			ans = temp1;
// 		else
// 			ans = min(temp1,temp2);

// 		cout <<"Case #" << i <<": "<<ans<<"\n";
// 	}

// 	return 0;
// }
