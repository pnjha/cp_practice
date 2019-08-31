// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=345&page=show_problem&problem=2683

#include<bits/stdc++.h>
#define SIZE 32
using namespace std;

struct trie{
	struct trie* children[2] = {NULL};
	int val = 0;
};

void insert(struct trie* root,int key){

	struct trie* temp = root;
	bool val = false;

	for(int i = SIZE-1;i>=0;i--){

		val = key&1<<i;

		if(!temp->children[val]){
			temp->children[val] = new trie();
		}

		if(i!=0){
			temp = temp->children[val];
		}
	}
	temp->val = key;
}

int query(struct trie* root,int key){

	struct trie* temp = root;
	int ans = 0;
	bool val = false;

	for(int i = SIZE-1;i>=0;i--){

		val = key&1<<i;		

		if(temp->children[1-val]){
			ans = ans | 1<<i;
			temp = temp->children[1-val]; 
		}else{
			temp = temp->children[val];
		}
	}	

	return ans;
}

int find_max_xor_subarray(vector<int>& arr){

	int prefix_xor = 0,max_val = INT_MIN;

	struct trie* root = new trie();	

	insert(root,prefix_xor);

	for(int i = 0;i<arr.size();i++){

		prefix_xor = prefix_xor ^ arr[i];
		insert(root,prefix_xor);

		max_val = max(max_val, query(root,prefix_xor));
	}


	return max_val;
}

int main(){

	int t,n;
	cin>>t;

	vector<int> arr;

	while(t--){

		cin>>n;

		arr.clear();
		arr.resize(n);

		for(int i = 0;i<n;i++)
			cin>>arr[i];

		cout<<find_max_xor_subarray(arr)<<"\n";
	}

	// cout<<"\n";
	
	return 0;
}
