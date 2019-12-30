// https://cses.fi/problemset/task/1649
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void build_tree(vector<ll>& tree, vector<ll>& arr, int l, int r, int index){
	if(l>r) return;
	if(l == r){
		tree[index] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	build_tree(tree,arr,l,mid,2*index);
	build_tree(tree,arr,mid+1,r,2*index+1);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

ll query(vector<ll>& tree, int index, int l, int r, int ql, int qr){
	if(l>r || l>qr || r<ql) return LONG_MAX;
	if(ql<=l&&qr>=r)return tree[index];
	int mid = l + (r-l)/2;
	ll left = query(tree,2*index,l,mid,ql,qr);
	ll right = query(tree,2*index+1,mid+1,r,ql,qr);
	return min(left,right);
}

void update(vector<ll>& tree, vector<ll>& arr, int index, int l, int r, int idx, int val){
	if(l>r || idx<l || idx>r) return;
	if(l == r){
		arr[idx] = val;
		tree[index] = val;
		return;
	}
	int mid = l + (r-l)/2;
	update(tree,arr,2*index,l,mid,idx,val);
	update(tree,arr,2*index+1,mid+1,r,idx,val);
	tree[index] = min(tree[2*index],tree[2*index+1]);	
}

int main(){

	// freopen("in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b,c;
	cin>>n>>q;

	vector<ll> arr(n), tree(4*n+1);
	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree(tree,arr,0,n-1,1);

	for(int i = 0;i<q;i++){
		cin>>a>>b>>c;
		if(a == 1){ //point update operation
			b--;
			update(tree,arr,1,0,n-1,b,c);
		}else if(a == 2){ // range min query
			b--,c--;
			cout<<query(tree,1,0,n-1,b,c)<<"\n";
		}
	}

	return 0;
}
