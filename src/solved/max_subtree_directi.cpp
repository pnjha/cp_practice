#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n){
	parent.resize(n,0);
	size.resize(n,1);
	for(int i = 0;i<n;i++) parent[i] = i;
}

int find_root(int a){
	while(parent[a]!=a){
		parent[a] = parent[parent[a]];
		a = parent[a];
	}
	return a;
}

int make_union(int a, int b){
	int roota = find_root(a);
	int rootb = find_root(b);
	int s=-1;
	if(roota!=rootb){
		if(size[roota]>size[rootb]){
			parent[rootb] = roota;
			size[roota] += size[rootb];
			s = size[roota];
		}else{
			parent[roota] = rootb;
			size[rootb] += size[roota];
			s = size[rootb];
		}
	}
	return s;
}

int main(){

	int a,temp,max_val=INT_MIN;
	cin>>a;

	initialize(a);

	vector<int> c(a-1), b(a-1), d, ans;	
	for(int i = 0;i<a-1;i++){
		cin>>b[i]>>c[i];
	}

	unordered_map<int,int> ump;
	while(cin>>temp){
		d.push_back(temp);
		ump[temp] = temp;
	}

	for(int i = 0;i<a-1;i++){
		if(ump.find(i)==ump.end()){
			max_val = max(max_val,make_union(b[i],c[i]));
		}
	}

	ans.push_back(max_val);
	for(int i = d.size()-1;i>=0;i--){
		max_val = max(max_val,make_union(b[i],c[i]));
		ans.push_back(max_val);
	}

	for(int i = ans.size();i>=0;i--) cout<<ans[i]<<" ";
	cout<<"\n";

	return 0;
}
