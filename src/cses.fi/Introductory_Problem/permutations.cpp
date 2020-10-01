#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	if(n == 1){
		cout<<1<<"\n";
		return 0;
	}

	if(n == 2 || n == 3){
		cout<<"NO SOLUTION\n";
		return 0;
	}

	if(n == 4){
		cout<<"2 4 1 3\n";
		return 0;
	}

	int k = 0;
	if(n%2==0)
		k = n;
	else
		k = n-1;

	while(k!=0){
		cout<<k<<" ";
		k -= 2;
	}

	if(n%2==0)
		k = n-1;
	else
		k = n;	

	while(k!=-1){
		cout<<k<<" ";
		k -= 2;
	}

	cout<<"\n";
	return 0;
}
