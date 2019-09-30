// https://www.codechef.com/LTIME76B/problems/CATFEED

#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	int flag = 0;
	int t,n,m,a,b;
	
	cin>>t;

	while(t--){
	     
          flag = 0;
          
		cin>>n>>m;

		int cnt[n+1];
		memset(cnt,0,sizeof(cnt));
		
		int arr[m];
		memset(arr,0,sizeof(arr));

		for(int i = 0;i<m;i++){

			cin>>arr[i];
		}
          for(int i = 0;i<m;i++){
                    
               a = arr[i];
                    
			for(int j = 1;j<=n;j++){

				if(cnt[a]>cnt[j]){
					flag = true;
					break;
				}
			}

			if(flag)
				break;
			
			cnt[a]++;
		}

		if(flag){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
			
		flag = false;
	}

	return 0;
}
