// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/0000000000170721
#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n){
	parent.clear();
	size.clear();
	parent.resize(n,0);
	size.resize(n,1);
	for(int i=0;i<n;i++) parent[i]=i;
}

int find_root(int a){
	while(parent[a]!=a){
		parent[a] = parent[parent[a]];
		a = parent[a];
	}
	return a;
}

bool make_union(int a, int b){
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
		return true;
	}
	return false;
}

int main(){

	freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t=0,n,m,ans,c,d,k;
	cin>>t;
	// cout<<t<<"\n";
	for(int i = 0;i<t;i++){
		cin>>n>>m;
		k=n;
		initialize(n);
		// cout<<n<<" "<<m<<"\n";
		for(int j=0;j<m;j++){
			cin>>c>>d;
			c--,d--;	
			if(make_union(c,d)) k--; 
		}
		ans = n-1+k-1;
		cout<<"Case #"<<(i+1)<<": "<<ans<<"\n";
	}

	return 0;
}








