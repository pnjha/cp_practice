// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fd0d
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	int t,n,m,q;
	cin>>t;

	for(int k = 1;k<=t;k++){

		ll ans = 0;

		cin>>n>>m>>q;
		int M[m],arr[n+1],a;
		memset(arr,0,sizeof(arr));

		for(int i = 0;i<m;i++){
			cin>>a;
			arr[a] = -1;
		}

		for(int i = 0;i<q;i++){
			cin>>a;
			for(int j = a;j<=n;j+=a){
				if(arr[j]!=-1){
					ans++;
				}
			}
		}


		cout <<"Case #" << k <<": "<<ans<<"\n";
	}	


	return 0;
}
