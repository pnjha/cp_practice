// https://cses.fi/problemset/task/1651
// https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

void build_tree(vector<ll>& tree, vector<ll>& arr, int index, int l , int r){
	if(l>r) return;
	if(l == r){
		tree[index] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	build_tree(tree,arr,2*index,l,mid);
	build_tree(tree,arr,2*index+1,mid+1,r);
	tree[index] = tree[2*index] + tree[2*index+1];
}

void range_update(vector<ll>& tree, vector<ll>& arr, int index, int l , int r, int ql, int qr, int val){
	if(l>r || ql>r || qr<l) return;
	if(l==r){
		tree[index] += val;
		arr[l] += val;
		return;
	}
	int mid = l + (r-l)/2;
	range_update(tree,arr,2*index,l,mid,ql,qr,val);
	range_update(tree,arr,2*index+1,mid+1,r,ql,qr,val);
	tree[index] = tree[2*index] + tree[2*index+1];
}

void lazy_update(vector<ll>& tree, vector<ll>& lazy, int index, int l, int r, int ql, int qr, int val){
	if(l>r || ql>r || qr<l) return;
	
	if(lazy[index]!=0){
		tree[index] += (r-l+1)*lazy[index];
		if(l!=r){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(ql<=l&&qr>=r){
		tree[index] += (r-l+1)*val;
		if(l!=r){
			lazy[2*index] += val;
			lazy[2*index+1] += val;
		}
		return;
	}

	int mid = l + (r-l)/2;
	lazy_update(tree,lazy,2*index,l,mid,ql,qr,val);
	lazy_update(tree,lazy,2*index+1,mid+1,r,ql,qr,val);
	tree[index] = tree[2*index] + tree[2*index+1];
}

ll lazy_query(vector<ll>& tree, vector<ll>& lazy, int index, int l, int r, int ql, int qr){
	if(l>r || ql>r || qr<l) return 0;
	if(lazy[index]!=0){
		tree[index] += (r-l+1)*lazy[index];
		if(l!=r){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(ql<=l&&qr>=r) return tree[index];
	
	int mid = l + (r-l)/2;
	ll left = lazy_query(tree,lazy,2*index,l,mid,ql,qr);
	ll right = lazy_query(tree,lazy,2*index+1,mid+1,r,ql,qr);
	return left+right;
}

int main(){

	// freopen("in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b,c,d;
	cin>>n>>q;

	vector<ll> arr(n), tree(4*n+1,0), lazy(4*n+1,0);
	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree(tree, arr, 1, 0 ,n-1);

	for(int i = 0;i<q;i++){
		cin>>a;
		if(a == 1){ //range update
			cin>>b>>c>>d;
			b--,c--;
			lazy_update(tree,lazy,1,0,n-1,b,c,d);
		}else{ //point query
			cin>>b;
			--b;
			cout<<lazy_query(tree,lazy,1,0,n-1,b,b)<<"\n";
		}
	}
	
	return 0;
}

/*
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
*/
