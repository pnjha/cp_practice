// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
//segment tree
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> arr, tree;

//store count of even numbers
void build_tree(int index, int l, int r){
	if(l>r) return;
	if(l==r){
		tree[index] = (arr[l]%2==0)?1:0;
		return;
	}
	int mid = l + (r-l)/2;
	build_tree(2*index,l,mid);
	build_tree(2*index+1,mid+1,r);
	tree[index] = tree[2*index] + tree[2*index+1];
}

void update(int index, int l, int r, int idx, int val){
	if(l>r || idx>r || idx<l) return;
	if(l==r){
		if(arr[l]%2==0&&val%2==1){
			tree[index]--;
			arr[l] = val;
		}else if(arr[l]%2==1&&val%2==0){
			tree[index]++;
			arr[l] = val;
		}
		return;
	}
	int mid = l + (r-l)/2;
	update(2*index,l,mid,idx,val);
	update(2*index+1,mid+1,r,idx,val);
	tree[index] = tree[2*index] + tree[2*index+1];	
}

ll query(int index, int l ,int r, int ql, int qr){
	if(l>r || ql>r || qr<l) return 0;
	if(ql<=l&&qr>=r) return tree[index];
	int mid = l + (r-l)/2;
	ll left = query(2*index,l,mid,ql,qr);
	ll right = query(2*index+1,mid+1,r,ql,qr);
	return left+right;
}

int main(){

	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,q,a,b,c;
	cin>>n;

	arr.clear(),arr.resize(n);
	tree.clear(),tree.resize(4*n+1);

	for(int i = 0;i<n;i++) cin>>arr[i];

	build_tree(1,0,n-1);

	cin>>q;

	for(int i = 0;i<q;i++){
		cin>>a>>b>>c;
		if(a == 0){
			b--;
			update(1,0,n-1,b,c);
		}else if(a == 1){
			b--,c--;
			cout<<query(1,0,n-1,b,c)<<"\n";
		}else if(a == 2){
			b--,c--;
			cout<<((c-b+1)-query(1,0,n-1,b,c))<<"\n";
		}
	}

	return 0;
}


/*
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive. 

6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

2
2
4
*/