#include<bits/stdc++.h>

using namespace std;

void print_arr(int *arr, int n){
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<"\n";
}

void build_tree(int *tree, int *arr, int s, int e, int index){
	if(s>e) return;
	if(s==e){
		tree[index] = arr[s];
		return;
	}
	int mid = s+(e-s)/2;
	build_tree(tree, arr, s, mid, 2*index);
	build_tree(tree, arr, mid+1, e, 2*index+1);
	tree[index] = max(tree[2*index],tree[2*index+1]);
}

int query(int *tree, int index, int s, int e, int qs, int qe){
	if(s>e || qs>e || qe<s) return INT_MIN;
	if(qs<=s&&e<=qe) return tree[index];
	int mid = s+(e-s)/2;
	int left = query(tree,index*2,s,mid,qs,qe);
	int right = query(tree,index*2+1,mid+1,e,qs,qe);
	return max(left,right);
}

//point update
void update(int *tree, int *arr, int index, int s, int e, int val, int i){
	if(s>e || i>e || i<s) return;
	if(s==e){ 
		tree[index] = val;
		arr[i] = val;
		return;
	}
	int mid = s+(e-s)/2;
	update(tree, arr, 2*index, s, mid, val, i);
	update(tree, arr, 2*index+1, mid+1, e, val, i);
	tree[index] = max(tree[2*index],tree[2*index+1]);
}

//range update -> add all elements in a range qs to qe with a particular value val
//O(n) -> n is number of elements in original array
void range_update(int *tree, int *arr, int index, int s, int e, int val, int qs, int qe){
	if(s>e || qe<s || qs>e) return;
	if(s==e){
		tree[index] += val;
		arr[s] += val;
		return;
	}
	int mid = s+(e-s)/2;
	range_update(tree, arr, 2*index, s, mid, val, qs, qe);
	range_update(tree, arr, 2*index+1, mid+1, e, val, qs, qe);
	tree[index] = max(tree[2*index],tree[2*index+1]);
}

int main(){

	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int tree_size = 4*n+1;
	int *tree = new int[tree_size];
	build_tree(tree, arr, 0, n-1, 1);
	print_arr(tree,tree_size);
	cout<<query(tree, 1, 0, n-1, 0, 2)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 3)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 4)<<"\n";
	update(tree,arr,1,0,n-1,10,3);
	cout<<query(tree, 1, 0, n-1, 0, 2)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 3)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 4)<<"\n";
	update(tree,arr,1,0,n-1,4,3);
	cout<<query(tree, 1, 0, n-1, 0, 2)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 3)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 4)<<"\n";
	range_update(tree, arr, 1, 0, n-1, 2, 0, n-1);
	cout<<query(tree, 1, 0, n-1, 0, 2)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 3)<<"\n";
	cout<<query(tree, 1, 0, n-1, 0, 4)<<"\n";
	return 0;
}






























