// https://cses.fi/problemset/task/1146
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;


unordered_map<ll, ll> cache;

ll c(ll n) {

	if(n == 0) 
		return 0;
	
	if(n == 1) 
		return 1;
	
	if(cache[n])
		return cache[n];
	
	ll z = n;
	ll a = 1;
	
	while (z >>= 1)
		a <<= 1;
	a -= 1;
	ll b = n - a;
	
	cache[n] = c(a) + b +c(b-1);
	
	return cache[n];
}

int main() {
	ll n;
	cin >> n;
	cout << c(n) << endl;;
}

// ll count_bits(ll n){

// 	if(n == 0)
// 		return 0;

// 	ll cnt = 0, start = 0,temp,x;
// 	ll q = floor(n/8);

// 	if(q&1){
// 		x = (q-1)/2;
// 		start = (q-1)*8;
// 	}else{
// 		x = q/2;
// 		start = q*8;
// 	}
	
// 	if(q>0){
// 		cnt += (x*(2*32+(x-1)*16))/2;
// 	}
// 	else
// 		start = 1;

// 	for(ll i = start;i<=n;i++){
// 		temp = i;
// 		while(temp){
// 			cnt++;
// 			temp = temp - (temp&(-temp));
// 		}
// 	}

// 	return cnt;
// }

// int main(){

// 	ll n;
// 	cin>>n;

// 	cout<<count_bits(n)<<"\n";

// 	return 0;
// }








