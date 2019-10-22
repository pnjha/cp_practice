// https://www.codechef.com/COOK111B/problems/DOR
#include<bits/stdc++.h>
#define ll long long int 
#define ld long double

using namespace std;

ll  bin_dec(string num){ 
    ll res = 0,base = 1,len = num.length(); 
    for(ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') res += base; 
        base = base * 2; 
    } 
    return res; 
}

string dec_bin(ll n,ll index){
	ll s = 0;
	string str= "";
    for (int i = index; i >= 0; i--){ 
        s = n >> i; 
        if(s & 1) str += '1'; 
        else str += '0'; 
    } 
    return str;
} 

ll get_max_val(ll left,ll right){

	string temp = "",str1 = "",str2 = "";
	str1 = dec_bin(left,log2((ld)left));
	str2 = dec_bin(right,log2((ld)right));

	ll l1 = str1.length(),l2 = str2.length(), k = 0;

	for(int k=0;k<(l2-l1);k++) temp += '0';
	str1 = temp + str1;
	
	for(k = 0;k<l2;k++) if(str1[k]!=str2[k]) break;
	for(int j=k;j<l2;j++)str1[j] = '1';
		
	return bin_dec(str1);

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t,l,r;
	cin>>t;

	while(t--){
		cin>>l>>r;
		cout<<get_max_val(l,r)<<"\n";
	}

	return 0;
}
