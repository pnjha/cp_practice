#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,ans=0;
	cin>>n;

	vector<int> arr = {9,900,90000,900000};

	if(n<10){
		ans = n;
	}else if(n>=10 && n <100){
		ans = 9;
	}else if(n>=100 && n<1000){
		ans = 9 + (n - 100 + 1);
	}else if(n>=1000 && n<10000){
		ans = 9 + 900;
	}else if(n>=10000 && n<100000){
		ans = 9 + 900 + (n-10000+1);
	}else if(n>=100000){
		ans = 9 + 900 + 90000;
	}

	cout<<ans<<"\n";

	return 0;
}
