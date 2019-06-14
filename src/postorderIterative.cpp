// pre-order traversal is root-left-right, and post order is left-right-root. modify the code for pre-order to make it root-right-left, and then reverse the output so that we can get left-right-root .

// Create an empty stack, Push root node to the stack.
// Do following while stack is not empty.

// 2.1. pop an item from the stack and print it.

// 2.2. push the left child of popped item to stack.

// 2.3. push the right child of popped item to stack.

// reverse the ouput.

#include<bits/stdc++.h>

using namespace std;

struct node{
	int value;
	struct node* left;
	struct node* right;
};

vector<int> postOrder(struct node *root){

	vector<int> ans;
	if(!root)
		return ans;

	stack<struct node*> s;
	struct node* temp;

	s.push(root);

	while(!s.empty()){

		temp = s.top();
		s.pop();

		ans.push_back(temp->value);

		if(temp->left)
			s.push(temp->left);
		if(temp->right)
			s.push(temp->right);

	}

	reverse(ans.begin(),ans.end());

	return ans;
}