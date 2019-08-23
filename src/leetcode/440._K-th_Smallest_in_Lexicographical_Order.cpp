// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include<bits/stdc++.h>

using namespace std;

struct trie_node{
	long long int cnt = 0;
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
			ptr->children[val[i]-'0']->cnt = 0;
		}

		ptr->children[val[i]-'0']->cnt++;

		if(i!=val.length()-1)
			ptr = ptr->children[val[i]-'0'];
	}

	ptr->is_word = true;

}

bool preorder_traversal(trie_node *root, int& k, int& ans, int num){

	// cout<<k<<" "<<ans<<"\n";

	if(!root || k < 0)
		return false;

	for(int i = 0;i<10;i++){

		if((root->children[i]) && (k - root->children[i]->cnt) > 0){
			k = k - root->children[i]->cnt;
			continue;
		}

		if(root->children[i]){

			ans = ans * 10 + i;

			if(root->is_word)
				k--;

			if(k == 0)
				return true;

			if(preorder_traversal(root->children[i],k,ans,num))
				return true;

			ans /= 10;			
		}
	}
	return false;
}

long long int cal_steps(long long int a,long long int b,long long int n){

	long long int steps = 0;

	while(a <= n){

		step += min(n+1, b) - a;
		a *= 10;
		b *= 10;
	}

	return steps;
}

long long int kth_number(long long int n, long long int k){

	long long int steps = 0,curr = 1;

	k--;

	while(k>0){

		steps = cal_steps(curr,curr+1,n);

		if(k - steps >= 0){
			k -= steps;
			curr++;
		}else{
			k--;
			curr *= 10;
		}

	}

	return curr;
}

int main(){

	// int n,ans = 0,k = 2;
	// cin>>n>>k;

	// trie_node *root = new trie_node();

	// for(int i = 1;i<n+1;i++){
	// 	root->cnt++;
 //        insert_node(root,to_string(i));
 //    }
	// preorder_traversal(root,k,ans,k);

	// cout<<ans<<"\n";


	int n,ans = 0,k = 2;
	cin>>n>>k;



	cout<<ans<<"\n";

	return 0;
}
