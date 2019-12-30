// https://cses.fi/problemset/task/1648
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void build_tree(vector<ll>& tree, vector<ll>& arr, int index, int s, int e){
	if(s>e) return;
	if(s == e) {
		tree[index] = arr[s];
		return; 
	}
	int mid = s + (e-s)/2;
	build_tree(tree,arr,2*index,s,mid);
	build_tree(tree,arr,2*index+1,mid+1,e);
	tree[index] = tree[2*index] + tree[2*index+1];
}

ll query(vector<ll>& tree, int index, int s, int e, int qs, int qe){
	if(s>e || qs>e || qe<s) return 0;
	if(qs<=s&&qe>=e){
		return tree[index];
	}
	int mid = s + (e-s)/2;
	ll l = query(tree,2*index,s,mid,qs,qe);
	ll r = query(tree,2*index+1,mid+1,e,qs,qe);
	return l+r;
}

void update(vector<ll>& tree, vector<ll>& arr, int index, int s, int e, int idx, ll val){
	if(s>e || idx>e || idx<s) return;
	if(s == e){
		tree[index] = val;
		arr[idx] = val;
		return;
	}
	int mid = s + (e-s)/2;
	update(tree,arr,2*index,s,mid,idx,val);
	update(tree,arr,2*index+1,mid+1,e,idx,val);
	tree[index] = tree[2*index] + tree[2*index+1];
}

int main(){

	// freopen("in","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b,c;
	cin>>n>>q;
	vector<ll> arr(n);
	vector<ll> tree(4*n+1);

	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree(tree,arr,1,0,n-1);

	for(int i = 0;i<q;i++){
		cin>>a>>b>>c;
		if(a == 1){ //point update
			b--;
			update(tree,arr,1,0,n-1,b,c);
		}else if(a == 2){ // range sum
			b--, c--;
			cout<<query(tree,1,0,n-1,b,c)<<"\n";
		}
	}

	return 0;
}

/*
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
*/













