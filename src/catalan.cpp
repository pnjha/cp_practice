#include<bits/stdc++.h>

using namespace std;

int binomialCoefficent(int n,int k){
	int res = 1;
	if(k>n-k)
		k = n - k;
	for(int i=0;i<k;i++){
		res *= n-i;
		res /= i+1;
	}
	//cout<<"Binomial Coefficent of n,k is: "<<res;
	return res;
}


void catalan(int n){
	cout<<"Catalan Number is: "<<binomialCoefficent(2*n,n)/(n+1);
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	catalan(n);
	return 0;
}
