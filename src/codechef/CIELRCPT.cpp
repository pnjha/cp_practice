#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,p,temp,cnt=0;
	cin>>t;

	while(t--){
		cnt = 0;
		cin>>p;

		while(p){
			temp = (int)log2(p);
			temp = (int)pow(2,temp);
			cnt++;
			if(temp>2048){
				temp = 2048;
			}
			p -= temp;
		}

		cout<<cnt<<"\n";
	}

	return 0;
}
