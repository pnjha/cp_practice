#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,x,y,n,k,p,c;
	cin>>t;

	bool flag = true;

	while(t--){

		cin>>x>>y>>k>>n;

		for(int i = 0;i<n;i++){

			cin>>p>>c;
			
			if(p>=(x-y)){

				if(c<=k){
					flag =false;
				}

			}
		}

		if(flag)
			cout<<"UnluckyChef\n";
		else
			cout<<"LuckyChef\n";

		flag = true;
	}

	return 0;
}
