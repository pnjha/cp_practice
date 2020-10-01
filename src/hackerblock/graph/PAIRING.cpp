// https://online.codingblocks.com/player/33819/content/13653/5256
#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n){

	parent.clear();
	parent.resize(n,0);

	for(int i = 0;i<n;i++)
		parent[i] = i;

	size.clear();	 
	size.resize(n,1);
}

int find_root(int a){
	if(a == parent[a])
		return a;
	return parent[a] = find_root(parent[a]);
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

int main(){

	int n,m,a,b;
	cin>>n>>m;

	initialize(n);

	for(int i = 0;i<m;i++){
		cin>>a>>b;
		make_union(a,b);
	}

	vector<int> components_sizes;

	for(int i = 0;i<parent.size();i++){
		if(i == parent[i]){
			components_sizes.push_back(size[i]);			
		}
	}

	long long ans = 0;

	for(int i = 0;i<components_sizes.size();i++){
		for(int j = i+1;j<components_sizes.size();j++){
			ans += components_sizes[i] * components_sizes[j];
		}
	}

	cout<<ans<<"\n";

	return 0;
}
