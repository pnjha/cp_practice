#include<bits/stdc++.h>
using namespace std;

void binomialCoefficent(int n,int k){
	int res = 1;
	if(k>n-k)
		k = n - k;
	for(int i=0;i<k;i++){
		res *= n-i;
		res /= i+1;
	}
	cout<<"Binomial Coefficent of n,k is: "<<res;
}

int main(){
	int n,k;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of k: ";
	cin>>k;
	binomialCoefficent(n,k);
	return 0;
}
