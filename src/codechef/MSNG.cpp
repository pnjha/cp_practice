// https://www.codechef.com/OCT19B/problems/MSNG
#include<bits/stdc++.h>
#define ll long long int
#define MAXVAL 1000000000000
#define MAXBASE 36

using namespace std;

map<char,int> char_map;
unordered_map<int,vector<string>> ump;
map<ll,ll> mp;

void create_mapping(){
	char c = '0';
	for(int i = 0;i<10;i++)char_map[c+i] = i;
	c = 'A';
	for(int i = 0;i<26;i++) char_map[c+i] = i+10;
}

ll power(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res = res * a;
		if(res > MAXVAL) return -1;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll get_decimal(string str, ll base){
	ll num = 0,p=0,f;
	for(int k = str.length()-1;k>=0;k--){
		f = power(base,p);
		
		if(f == -1) return -1;
		num += char_map[str[k]]*f;
		if(num>MAXVAL) return -1;
		p++;
	}
	return num;
}

void generate_all_numbers(ll val){
	if(ump[-1].size()==0) return;

	vector<string> v = ump[-1];
	ll n = v.size();

	for(int i = 0;i<n;i++){

		string str = v[i];
		int base = INT_MIN;
		map<ll,ll> temp_mp;
		
		for(int j = 0;j<str.length();j++){
			if(base<char_map[str[j]]) base = char_map[str[j]];
		}

		base = base + 1;

		for(int j = base;j<=MAXBASE;j++){
			
			ll num = 0,p=0,f;

			for(int k = str.length()-1;k>=0;k--){
				f = power(j,p);
				if(f==-1) {num = MAXVAL+4;break;}
				num += char_map[str[k]]*f;
		        if(num>MAXVAL) break;
				p++;
			}			
			if(num>=0&&num<=MAXVAL) temp_mp[num]++;
		}

		for(auto x : temp_mp){
			if(x.second>0) mp[x.first]++;
		}
	}
}

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	create_mapping();

	ll t,n,a;
	string s;
	cin>>t;

	while(t--){
		cin>>n;
		ll ans = 0;

		ump.clear(),mp.clear();

		for(int i = 0;i<n;i++){
			cin>>a>>s;
			if(a!=-1){
				if(ump[a].size()==1){
					if(ump[a][0]!=s) ump[a].push_back(s);
				}else ump[a].push_back(s);
			}else if(a==-1) ump[a].push_back(s);
		}

		n = ump.size() + (ump[-1].size()>0?ump[-1].size()-1:0);

		ll val = LONG_MIN,b;

		for(auto x: ump){
			if(x.first!=-1 && x.second.size()==1){
				b = get_decimal(x.second[0],x.first);
				if(b == -1){ ans = -1; break;}
				if(val==LONG_MIN) val = b;
				if(val!=b || b>MAXVAL){ans = -1;break;}
				mp[b]++;
				
			}else if(x.first!=-1 && x.second.size()>1){
				ans = -1;
				break;
			}
		}

		if(ans != -1){

			if(val == LONG_MIN) val = LONG_MAX;
			generate_all_numbers(val);
			ll min_val = LONG_MAX;

			for(auto x : mp){
				// cout<<x.first<<" "<<x.second<<"\n";
				if(x.second == n){
					if(min_val>x.first) min_val = x.first;
				}
			}

			if(min_val == LONG_MAX) ans = -1;
			else ans = min_val;
		}

		if(ans>MAXVAL) ans = -1;
		cout<<ans<<"\n";
	}
	return 0;
}