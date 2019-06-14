#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ll t = 0,temp = 0,size = 0,a,b,A = 0,B = 0,I = 0;
	cin>>t;

	vector<int> S;

	while(t--){

		cin>>size>>a>>b;
		
		while(size--){
			cin>>temp;
			S.push_back(temp);
		}

		if(a%b==0||b%a==0){

			for(int i = 0;i<S.size();i++){
				if(S[i]%a==0&&S[i]%b==0){
					I++;
					S[i] = INT_MIN;
				}
			}
		}

		for(int i = 0;i<S.size();i++){

			if(S[i]%a==0&&S[i]!=INT_MIN)
				A++;
			
			if(S[i]%b==0&&S[i]!=INT_MIN)
				B++;
		}

		if(a==b){
			if(I%2==1){
				cout<<"BOB\n";
			}else{
				cout<<"ALICE\n";
			}
		}else if(I==0){

			if(A<=B)
				cout<<"ALICE\n";
			else
				cout<<"BOB\n";
		}else{

			// if(B<=A){
			// 	cout<<"BOB\n";
			// }else{
			// 	cout<<"ALICE\n";
			// }

			if(I%2==1){

				if(B<=A)
					cout<<"BOB\n";
				else
					cout<<"ALICE\n";

			}else{

				if(A<=B)
					cout<<"ALICE\n";
				else
					cout<<"BOB\n";
			}
		}

		S.clear();
		A = 0;
		B = 0;
		I = 0;
	}

	return 0;
}