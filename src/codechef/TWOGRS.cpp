// https://www.codechef.com/COOK110B/problems/TWOGRS
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool subset_sum(ll s,ll a,ll b,ll c){

	vector<bool> v(s+1,false);
	v[0] = true;

	vector<int> coins;
	
	while(a--)
		coins.push_back(1);
	while(b--)
		coins.push_back(2);
	while(c--)
		coins.push_back(3);

	for(int i = 0;i<coins.size();i++){
		for(int j = v.size()-1;j>0;j--){
			if(j-coins[i]>=0 && v[j-coins[i]])
				v[j] = true;
		}
	}

	return v.back();
}

bool is_possible_greedy(ll s,ll a,ll b,ll c){

	while(true){

		if(s == 0)
			return true;
		if(s>=3 && c>0)
			s = s - 3;
		else if(s>=2 && c>2)
			s = s - 2;
		else if(s>=1 && c>1)
			s = s - 1;
		else
			return false;

		if(s<0)
			break;
	}

	return false;
}

bool is_possible_greedy_2(ll s,ll a,ll b,ll c){

	ll s1=0,s2=0;

	if((a/3)<=c){
		c = c - (a/3); 
		a = a % 3;
	}

	if((b/3)<=c){
		c = c - 2*(b/3);
		b = b % 3;
	}

	if((a/2)<=b){
		b = b - (a/2);
		a = a % 2;
	}

	

	// cout<<"hello: "<<a<<" "<<b<<" "<<c<<"\n";

	while(c--){
		if(s1<=s2)
			s1 += 3;
		else
			s2 += 3;
	}

	while(b--){
		if(s1<=s2)
			s1 += 2;
		else
			s2 += 2;
	}

	while(a--){
		if(s1<=s2)
			s1 += 1;
		else
			s2 += 1;
	}

	return (s1 == s2);
}

int main(){

	ll t,a,b,c,s = 0;

	cin>>t;

	while(t--){
		
		cin>>a>>b>>c;

		s = a*1+b*2+c*3;
		
		if((s)%2==1){
			cout<<"NO\n";
		}else{
			if(is_possible_greedy_2(s,a,b,c)){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}

	return 0;
}
