#include<bits/stdc++.h>

using namespace std;

//insert, delete, search operations need to be implemented

struct node{

	int value;
	struct node* prev;
	struct node* next;
};

class LRU{

	unordered_map<int,struct node*> hashTable;
	struct node *head = NULL,*tail = NULL;
	
	const int size = 10;

	//called from search
	void insert(int value){
		
		if(hashTable.size()+1>size){
			deleteLRUElement();	
		}
		
		struct node *temp = (struct node*)malloc(sizeof(struct node*));
		temp->value = value;

		if(!head&&!tail){
			head = temp;
			tail = head;
			head->next = NULL;
			head->prev = NULL;
		}else{
			temp->prev = tail;
			temp->next = NULL;
			tail = tail->next;
		}

		hashTable[value] = temp;	
	}

	//called from insert
	void deleteLRUElement(){
		struct node* ptr = head;
		head = head->next;
		hashTable.erase(ptr->value);
		free(ptr);
	}

public:

	void search(int value){
		if(hashTable.find(value)==hashTable.end()){
			insert(value);
		}else{
			struct node* ptr = hashTable[value];
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			ptr->prev = tail;
			ptr->next = NULL; 
		}
	}
};

int main(){

	return 0;
}
