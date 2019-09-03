// https://www.spoj.com/problems/CHAIN/
#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n){

	parent.clear();
	parent.resize(n+1);

	for(int i = 0;i<n+1;i++)
		parent[i] = i;

	size.clear();
	size.resize(n+1,1);
}

int find_root(int a){

	while(parent[a]!=a)
		a = parent[a];

	return a;
}

void make_union(int a, int b){

	int roota = find_root(a);
	int rootb = find_root(b);

	if(roota!=rootb){
		if(size[roota]>size[rootb]){

			parent[rootb] = roota;
			size[roota] += size[rootb];

		}else{

			parent[roota] = rootb;
			size[rootb] += size[roota];
		}
	}
}

bool process_query(int n, int a, int b, int c){
	
	if(b>n||c>n)
		return false;

	if(a == 1){

		if(b==c)
			return true;

		int rootb = find_root(b);
		int rootc = find_root(c);

		if(rootc!=b && rootb!=c && rootc == rootb){
			return true;
		}

	}else{

		if(b == c)
			return false;
		make_union(b,c);
		return true;
	}
	return false;
}

int main(){

	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n,k,cnt = 0,a,b,c;
	cin>>t;

	while(t--){

		cin>>n>>k;
		cnt = 0;

		initialize(n);

		for(int i = 0;i<k;i++){
			cin>>a>>b>>c;
			// cout<<a<<" "<<b<<" "<<c<<"\n";
			if(!process_query(n,a,b,c)){
				cnt++;
			}
		}

		cout<<cnt<<"\n";
	}

	return 0;
}