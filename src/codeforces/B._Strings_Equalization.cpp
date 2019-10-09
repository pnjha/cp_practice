// https://codeforces.com/contest/1241/problem/B
#include<bits/stdc++.h>

using namespace std;

bool bfs(string& a, string& b){

	bool flag = false;

	set<string> sa,sb,s,k,temp,seen,pa,pb;
	sa.insert(a);
	sb.insert(b);

	while(sa.size()!=0 && sb.size()!=0){

		s.clear();
		k.clear();
		temp.clear();

		if(sa.size()<sb.size()){
			flag = true;
		}else{
			flag = false;
		}

		if(flag){
			s = sa;
			k = sb;
		}else{
			s = sb;
			k = sa;
		}
		
		for(auto x : s){

			seen.insert(x);
			string str = x,d;

			for(int i = 1;i<str.length();i++){
				d = str;
				d[i] = d[i-1];
				if(k.find(d)!=k.end()){
					// cout<<"Element found: "<<d<<"\n";
					return true;
				}
				else if(seen.find(d)==seen.end()){
					// seen.insert(d);
					temp.insert(d);
				}
				d = str;
				d[i-1] = d[i];
				if(k.find(d)!=k.end()){
					// cout<<"Element found: "<<d<<"\n";
					return true;
				}
				else if(seen.find(d)==seen.end()){
					// seen.insert(d);
					temp.insert(d);
				}
			}
		}

		if(sa.size()<sb.size()){
			sa = temp;
		}else{
			sb = temp;
		}
	}

	return false;
}

bool solve(string& a, string& b){	

	vector<int> arr(26,0);

	for(int i = 0;i<a.length();i++)
		arr[a[i]-'a']++;

	for(int i = 0;i<b.length();i++)
		if(arr[b[i]-'a']>0)
			return true;

	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("input.txt","r",stdin);

	int q;
	string a,b;
	cin>>q;

	while(q--){

		cin>>a>>b;

		if(a == b){
			cout<<"YES\n";
			continue;	
		}

		if(a.length()!=b.length() || a.length()<2&&a!=b){
			cout<<"NO\n";
			continue;
		}


		// if(bfs(a,b)){
		// 	cout<<"YES\n";
		// }else{
		// 	cout<<"NO\n";
		// }

		if(solve(a,b)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}

