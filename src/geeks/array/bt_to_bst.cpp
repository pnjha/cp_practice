// https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/?ref=lbp
#include<bits/stdc++.h>

using namespace std;

vector<int> inorder;

void inorder_traversal(vector<int> tree, int index){
	if(index >= tree.size()) return;
	inorder_traversal(tree, 2*index+1);  
	inorder.push_back(tree[index]);
	inorder_traversal(tree, 2*index+2);
}

void print_arr(vector<pair<int,int>>arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i].first<<" ";
	cout<<"\n";
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i].second<<" ";
	cout<<"\n";
	cout<<"##############\n";
}

int min_swaps(vector<int> tree){
	inorder.clear();
	inorder_traversal(tree,0);
	inorder = {3,10,2,1,4};
	vector<pair<int,int>> arr;
	for(int i = 0;i<inorder.size();i++) arr.push_back({inorder[i],i});
	sort(arr.begin(),arr.end());
	int i = 0, cnt = 0, temp=0;
	
	while(i<inorder.size()){
		if(arr[i].second != i){
			while(arr[i].second != i){
				print_arr(arr);
				int temp = arr[i].first, temp_idx;
				arr[i].first = arr[arr[i].second].first;
				arr[arr[i].second].first = temp;
				temp_idx = arr[arr[i].second].second;
				arr[arr[i].second].second = arr[i].second;
				arr[i].second = temp_idx;
				cnt++;
			}
		}
		i++;
	}
	return cnt;
}
 
int main(){
	vector<int> tree = {3,10,2,1,4};
	cout<<min_swaps(tree)<<"\n";
	return 0;
}
