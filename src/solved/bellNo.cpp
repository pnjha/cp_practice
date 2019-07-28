#include<bits/stdc++.h>
using namespace std;

void bellNumber(int n,int k){
	int bell[n+1][k+1];
	memset(bell,0,sizeof(bell));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j==1||j==i)
				bell[i][j] = 1;
			else{
				bell[i][j] = j*bell[i-1][j] + bell[i-1][j-1];
			}
		}
	}
	cout<<"Total Number of partitions of "<<n<<" numbers in "<<k<<" sets is "<<bell[n][k];
}

int main(){
	int n,k;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of k: ";
	cin>>k;
	bellNumber(n,k);
	return 0;
}
