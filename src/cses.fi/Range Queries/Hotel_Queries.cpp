// https://cses.fi/problemset/task/1143
#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

vector<ll> arr, tree;

//range max segtree 
void build_tree(int index,int l,int r){
	if(l>r) return;
	if(l == r){
		tree[index] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	build_tree(2*index,l,mid);
	build_tree(2*index+1,mid+1,r);
	tree[index] = max(tree[2*index],tree[2*index+1]);
}

int idx;

void query(int index, int l, int r, int val, bool& done){
	if(done) return;
	if(tree[index]<val) return;
	if(l == r){
		if(arr[l]>=val){
			tree[index] -= val;
			done  = true;
			idx = l;
		}
		return;
	}
	int mid = l + (r-l)/2;
	query(2*index,l,mid,val,done);
	if(done) return;
	query(2*index+1,mid+1,r,val,done);
	tree[index] = max(tree[2*index], tree[2*index+1]);
}

int main(){

	// freopen("in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a;
	cin>>n>>q;

	arr.clear(), tree.clear();
	arr.resize(n,0),tree.resize(4*n+1,0);

	for(int i = 0;i<n;i++) cin>>arr[i];
	
	build_tree(1,0,n-1);

	for(int i = 0;i<q;i++){
		bool flag = false;
		idx = -1;
		cin>>a;
		query(1,0,n-1,a,flag);
		// cout<<flag<<" "<<idx<<"\n";
		if(flag) cout<<idx+1<<" ";
		else cout<<"0 ";
	}
	cout<<"\n";
	return 0;
}


/*

Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Output:
3 5 0 1 1

*/