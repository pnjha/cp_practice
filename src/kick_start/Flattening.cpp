// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666c

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> arr, int index, int& step, int cnt){

	// cout<<index<<"\n";

	if(cnt == 1){
		return;
	}

	int temp1 = step,temp2 = step,g,h = step;

	for(int i = index+1;i<arr.size()-1;i++){
				
		if(arr[i]!=arr[i-1]){
			g = arr[i];
			arr[i] = arr[i-1];
			dfs(arr,i,++temp1,cnt-1);
			arr[i] = g;
		}

		if(arr[i]!=arr[i+1]){
			g = arr[i];
			arr[i] = arr[i+1];
			dfs(arr,i,++temp2,cnt-1);
			arr[i] = g;
		}
	}

	if(temp1 == step)
		step =temp2;
	else if(temp2 == step)
		step =temp1;
	else
		step = min(temp1,temp2);

}


int main(){

	freopen("input.txt","r",stdin);

	int t,n,k,cnt = 0,g;

	cin>>t;

	for(int i = 0;i<t;i++){

		cin>>n>>k;

		vector<int> arr(n);

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		for(int i = 1;i<n;i++){
			if(arr[i]!=arr[i-1]){
				cnt++;
			}
		}		

		cnt = cnt - k;
		
		if(cnt<=0)
			cnt = 0;

		int temp1 = 0,temp2 = 0,ans = 0;
		bool flag1 = false, flag2 = false;

		if(cnt>0){

			for(int i = 1;i<n-1;i++){
				
				if(arr[i]!=arr[i-1]){
					flag1 = true;
					g = arr[i];
					arr[i] = arr[i-1];
					dfs(arr,i,++temp1,cnt-1);
					arr[i] = g;
				}

				if(arr[i]!=arr[i+1]){
					g = arr[i];
					flag2 = true;
					arr[i] = arr[i+1];
					dfs(arr,i+1,++temp2,cnt-1);
					arr[i] = g;
				}

				if(flag1 || flag2)
					break;
			}
		}

		if(temp1 == ans)
			ans = temp2;
		else if(temp2 == ans)
			ans = temp1;
		else
			ans = min(temp1,temp2);

		cout <<"Case #" << i <<": "<<ans<<"\n";
	}

	return 0;
}
