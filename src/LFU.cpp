#include<bits/stdc++.h>

using namespace std;

class LFU{

	struct node{
		int key;
		int value;
		int frequency;
		struct node *next;
	};

	struct node *head;
	unordered_map<int,struct node*> tlb;

public:

	void set(int key,int value){
		
	}

	int get(int key){
		if(tlb.find(key)!=tlb.end()){
			return tlb.find(key)->second->value;
		}
	}

};

int main(){



	return 0;
}