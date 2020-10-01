// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
#include<bits/stdc++.h>
#define SIZE 1000000000
using namespace std;

vector<int> num;
vector<int> pfactors;

void sieve(){

	for(int i = 0;i<num.size();i++){
		num[i] = i;
	}

	vector<int> psf;

	for(int i = 2;i<num.size();i++){
			
		if(num[i] == i){
			psf.push_back(i);
		}	

		for(int j = 0;j<psf.size() && i*psf[j] < num.size();j++){
			num[i*psf[j]] = min(num[i],psf[j]);
		}	
	}
}

void find_factors(int n){

	while(n>1){
		pfactors.push_back(num[n]);
		n = n / num[n];
	}
}

int main(){

	int n;
	cin>>n;

	num.clear();
	num.resize(SIZE,0);

	pfactors.clear();
	
	sieve();

	for(int i = 0;i<n+1;i++)
		cout<<num[i]<<" ";
	cout<<"\n";

	find_factors(n);

	for(int i = 0;i<pfactors.size();i++)
		cout<<pfactors[i]<<" ";

	cout<<"\n";

	return 0;
}
