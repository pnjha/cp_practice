// https://www.codechef.com/OCT19B/problems/SAKTAN

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll t,n,m,a,b,c;

	cin>>t;

	while(t--){

		cin>>n>>m>>c;

		int left[n], top[m];

		memset(left,0,sizeof(left));
		memset(top,0,sizeof(top));

		while(c--){

			cin>>a>>b;
			a--,b--;

			left[a] = (left[a] + 1)%2;
			top[b] = (top[b] + 1)%2;
		}

		ll cnt = 0,set_bits_top = 0;

		for(int j = 0;j<m;j++){
			if(top[j]==1)
				set_bits_top++;				
		}

		for(int i = 0;i<n;i++){
			if(left[i] == 0){
				cnt += set_bits_top;
			}else{
				cnt += (m-set_bits_top);
			}
		}

		cout<<cnt<<"\n";
	}

	return 0;
}