#include<bits/stdc++.h>

using namespace std;

struct trie_node{
	trie_node* children[10] =  {NULL};
	bool is_word = false;
};

void print_arr(vector<string>& arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void insert_node(trie_node *root, string val){

	trie_node *ptr = root;

	for(int i = 0;i<val.length();i++){

		if(!ptr->children[val[i]-'0']){
			ptr->children[val[i]-'0'] = new trie_node();
		}
		ptr = ptr->children[val[i]-'0'];
	}

	ptr->is_word = true;
}

void preorder_traversal(root,k){

	
	
}

int main(){

	vector<string> arr = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
	"16","17","18","19","20","21","22","23","24","25","26","28","110"};

	trie_node *root = new trie_node();

	for(int i = 0;i<arr.size();i++){
		insert_node(root, arr[i]);
	}

	int ans = stoi(preorder_traversal(root,k));

	cout<<ans<<"\n";

	return 0;
}
