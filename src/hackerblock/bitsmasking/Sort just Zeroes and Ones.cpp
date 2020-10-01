#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,temp;
	cin>>n;

	int zcnt = 0, ocnt = 0;

	for(int i = 0;i<n;i++){

		cin>>temp;

		if(temp==1)
			ocnt++;
		else
			cout<<"0 ";
	}

	while(ocnt--)
		cout<<"1 ";
	cout<<"\n";
	return 0;
}
