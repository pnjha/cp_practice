// https://online.codingblocks.com/app/player/33819/content/38737/4867
// https://www.quora.com/How-do-I-calculate-the-maximum-sub-segment-sum-in-a-segment-tree/answer/Ashwin-Krish
// https://github.com/ash1794/Share-Code/blob/master/GSS1.cpp
// https://www.youtube.com/watch?v=ohHWQf1HDfU -> divide and conquer stategy is used
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

struct st_node{
	ll prefix_sum = 0;
	ll suffix_sum = 0;
	ll segsum = 0;
	ll bestsum = 0;
};

vector<ll> arr;
st_node** tree;

ll _max(ll a, ll b, ll c){
	return max(c,max(a,b));
}

st_node* merge(st_node* left, st_node* right){
	st_node* parent = new st_node;
	parent->segsum = left->segsum + right->segsum;
	parent->prefix_sum = max(left->segsum+right->prefix_sum, left->prefix_sum);
	parent->suffix_sum = max(right->segsum+left->suffix_sum, right->suffix_sum);
	parent->bestsum = _max(left->bestsum, right->bestsum, left->suffix_sum+right->prefix_sum);
	return parent;
}

void build_tree(int index, int l ,int r){
	if(l>r) return;
	if(l==r){
		tree[index] = new st_node;
		tree[index]->segsum = arr[l];
		tree[index]->prefix_sum = arr[l];
		tree[index]->suffix_sum = arr[l];
		tree[index]->bestsum = arr[l];
		return;
	} 
	int mid = l + (r-l)/2;
	build_tree(2*index,l,mid);
	build_tree(2*index+1,mid+1,r);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
}
 
st_node* query(int index, int l ,int r, int ql, int qr){
	if(l>r || ql>r || qr<l) return NULL;
	if(ql<=l&&qr>=r){
		st_node* node = new st_node;
		node = tree[index];
		return node;
	}
	int mid = l + (r-l)/2;
	st_node* left, *right;
	left = query(2*index,l,mid,ql,qr);
	right = query(2*index+1,mid+1,r,ql,qr);
	if(!left) return right;
	if(!right) return left;
	return merge(left,right);
}

int main(){

	// freopen("in","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b;
	cin>>n;

	arr.clear(), arr.resize(n);
	tree = new st_node*[4*n+1];

	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree(1,0,n-1);
	
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>a>>b;
		a--,b--;
		st_node* ans = query(1,0,n-1,a,b);
		cout<<ans->bestsum<<"\n";
	}

	return 0;
}
