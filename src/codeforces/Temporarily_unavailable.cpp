// https://codeforces.com/contest/1282/problem/A
//wrong sol
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll temp,a,b,c,r,t,ans = 0;
	cin>>t;

	while(t--){
		cin>>a>>b>>c>>r;
		ans = 0;
		if(a>b){
			temp = a;
			a = b;
			b = temp;
		}
		if(a == b) ans = 0;
		else if(a == c || b == c){
			ans = b-a-(r==0?1:r);
		}else if(a<c&&c<b){
			ans = b-a-(c-r<a?(c-1):r)-(c+r>b?(b-c):r);
		}else if(c<a){
			ans = b-a-(c+r<a?-1:c+r-a);
		}else if(c>b){
			ans = b-a-(c-r>b?-1:b-(c-r));
		}
		if(ans<0) ans = 0;
		cout<<ans<<"\n";
	}

	return 0;
}

/*
9
1 10 7 1
3 3 3 0
8 2 10 4
8 2 10 100
-10 20 -17 2
-3 2 2 0
-3 1 2 0
2 3 2 3
-1 3 -2 2
*/

/*
7
0
4
0
30
5
4
0
3
*/