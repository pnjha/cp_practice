// https://www.codechef.com/JUNE20B/problems/EOEO

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll get_first_setbit_msb(ll n){
	ll index = 0,cnt = 0;
	while(n){
		if(n&1) index = cnt;
		n >>= 1;
		cnt++;
	}
	return index;
}

ll get_first_setbit_lsb(ll n){
	ll index = 0,cnt = 0;
	while(true){
		if(n&1){
			break;
		}
		n >>= 1;
		index++;
	}
	return index;
}

ll power(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

ll get_num(ll n,ll msb,ll lsb){
	ll num = n;
	num = num & ~(1l<<msb);
	// bitset<32> bset2(num);
	// cout << bset2 << endl;
	
	for(int i = 0;i<=lsb;i++){
		num >>= 1;
	}
	// bitset<32> bset3(num);
	// cout << bset3 << endl;
	// cout<<num<<"\n";
	return num;
}

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t = 0,n,ans = 0,lsb,msb;
	cin>>t;

	// cout<<(7 & ~(1<<2))<<"\n";

	while(t--){
		ans = 0;
		cin>>n;
		if(n%2==1) cout<<n/2<<"\n";
		else{
			msb = get_first_setbit_msb(n);
			lsb = get_first_setbit_lsb(n);
			if(msb == lsb) cout<<"0\n";
			else cout<<power(2l,(msb-lsb-1)) + get_num(n,msb,lsb)<<"\n";
		}
	}

	return 0;
}