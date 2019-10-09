// https://www.codechef.com/OCT19B/problems/MARM

#include<bits/stdc++.h>
#define  ll long long int 

using namespace std;

vector<ll> calculate_XOR(vector<ll> A){

	ll n = A.size();

	for(int i = 0;i<n;i++){
		A[i%n] = A[i%n] ^ A[n-(i%n)-1];
	}
	return A;
}


int main(){	

	freopen("input.txt","r",stdin);

	ll t,n,k;	
	cin>>t;

	while(t--){

		cin>>n>>k;

		vector<ll> A(n),A0(n),A1(n),A2(n),B(n,0),C1(n),C2(n);

		for(int i = 0;i<n;i++)
			cin>>A[i];

		A1 = calculate_XOR(A);
		A2 = calculate_XOR(A1);
		A0 = calculate_XOR(A2);

		// for(int i = 0;i<5;i++)
		// 	cout<<A1[i]<<" ";
		// cout<<"\n";

		// for(int i = 0;i<5;i++)
		// 	cout<<A2[i]<<" ";
		// cout<<"\n";

		// for(int i = 0;i<5;i++)
		// 	cout<<A0[i]<<" ";
		// cout<<"\n";		

		ll d = (k/n)%3;
		ll r = k%n;

		if(d == 0) C1 = A0;
		if(d == 1) C1 = A1;
		if(d == 2) C1 = A2;

		if((d+1)%3 == 0) C2 = A0;
		if((d+1)%3 == 1) C2 = A1;
		if((d+1)%3 == 2) C2 = A2;

		for(int i = r;i<n;i++)
			B[i] = C1[i];
		
		for(int i = 0;i<=r-1;i++)
			B[i] = C2[i];

		if(n&1 && k<=(n/2))
			B[n/2] = A[n/2];

		for(int i = 0;i<n;i++)
			cout<<B[i]<<" ";
		cout<<"\n";
 	}

	return 0;
}


// int main(){

// 	vector<ll> A = {1,2,3,4,5};
// 	vector<ll> A0,A1,A2;

// 	A1 = calculate_XOR(A);
// 	A2 = calculate_XOR(A1);
// 	A0 = calculate_XOR(A2);

// 	for(int i = 0;i<5;i++)
// 		cout<<A1[i]<<" ";
// 	cout<<"\n";

// 	for(int i = 0;i<5;i++)
// 		cout<<A2[i]<<" ";
// 	cout<<"\n";

// 	for(int i = 0;i<5;i++)
// 		cout<<A0[i]<<" ";
// 	cout<<"\n";

// 	return 0;
// }