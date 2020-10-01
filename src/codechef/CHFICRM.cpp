// https://www.codechef.com/JUNE20B/problems/CHFICRM

#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;

	while(t--){

		bool flag = true;

		unordered_map<int,int> ump;
		ump[5] = 0;
		ump[10] = 0;
		ump[15] = 0;
		ump[0] = INT_MAX;
		
		int n,a;
		cin>>n;

		for(int i = 0;i<n;i++){
			cin>>a;
			if(flag){
				if(a == 5) ump[a]++;
				else if(a == 10 && ump[5]>0){
					ump[5]--;
					ump[10]++;
				}
				else if(a == 15 && (ump[10]>0 || ump[5]>1)){
					ump[15]++;
					if(ump[10]>0){
						ump[10]--;
					}else if(ump[5]>1){
						ump[5] -= 2;
					}
				}
				else{
					flag = false;
				}
			}
		}

		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}



/*
3
2
5 10
2
10 5
2
5 15
*/