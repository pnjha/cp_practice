// https://codeforces.com/contest/1284/problem/A
#include<bits/stdc++.h>

using namespace std;

int main(){

	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m,q,x;
	cin>>n>>m;

	vector<string> a(n), b(m);

	for(int i = 0;i<n;i++) cin>>a[i];
	for(int i = 0;i<m;i++) cin>>b[i];

	cin>>q;

	for(int i = 0;i<q;i++){
		cin>>x;
		x--;
		cout<<(a[x%n]+b[x%m])<<"\n";
	}

	return 0;
}

/*
10 12
sin im gye gap eul byeong jeong mu gi gyeong
yu sul hae ja chuk in myo jin sa o mi sin
14
1
2
3
4
10
11
12
13
73
2016
2017
2018
2019
2020
*/