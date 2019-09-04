// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,m,k;
	cin>>n>>m>>k;

	vector<int> seq1(n),seq2(m);

	for(int i = 0;i<n;i++){
		cin>>seq1[i];
	}

	for(int i = 0;i<n;i++){
		cin>>seq2[i];
	}

	return 0;
}