#include<bits/stdc++.h>

using namespace std;

void morrisInorder(struct node *root){

	struct node *current = root,*inorderPredecessor = NULL;

	while(current){

		if(!current->left){

			cout<<current->val<<"\n";
			current = current->right;

		}else{

			inorderPredecessor = findInorderPredecessor(current);

			if(!inorderPredecessor){

				inorderPredecessor->right = current;
				current = current->left;

			}else{

				cout<<current->val<<"\n";
				inorderPredecessor->right = NULL;
				current = current->right;

			}

		}

	}

}

void morrisPreorder(struct node *root){

	struct node *current = root,*inorderPredecessor = NULL;

	while(current){

		if(!current->left){

			cout<<current->val<<"\n";
			current = current->right;

		}else{

			inorderPredecessor = findInorderPredecessor(current);

			if(!inorderPredecessor){

				cout<<current->val<<"\n";
				inorderPredecessor->right = current;
				current = current->left;

			}else{

				inorderPredecessor->right = NULL;
				current = current->right;

			}

		}

	}

}
