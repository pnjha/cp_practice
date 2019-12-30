// https://cses.fi/problemset/task/1647
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void build_tree(vector<ll>& tree, vector<ll>& arr, int index, int l, int r){
	if(l>r) return;

	if(l == r){
		tree[index] = arr[l];
		return;
	}

	int mid = l + (r-l)/2;
	build_tree(tree,arr,2*index,l,mid);
	build_tree(tree,arr,2*index+1,mid+1,r);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

int query(vector<ll>& tree, int index, int l, int r, int ql, int qr){
	if(l>r || ql>r || qr<l) return INT_MAX;
	
	if(ql<=l&&qr>=r) return tree[index];
	
	int mid = l + (r-l)/2;
	int left = query(tree,2*index,l,mid,ql,qr);
	int right = query(tree,2*index+1,mid+1,r,ql,qr);
	return min(left,right);
}

int main(){

	// freopen("in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,l,r,ans;
	cin>>n>>q;

	vector<ll> arr(n);
	vector<ll> tree(4*n+1);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	build_tree(tree,arr,1,0,n-1);

	// for(int i = 0;i<tree.size();i++) cout<<tree[i]<<" ";
	// cout<<"\n";

	for(int i = 0;i<q;i++){
		cin>>l>>r;
		l--,r--;
		cout<<query(tree,1,0,n-1,l,r)<<"\n";
	}

	return 0;
}
