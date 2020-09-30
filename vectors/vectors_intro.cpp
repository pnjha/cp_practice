#include<iostream>
#include<algorithm>
using namespace std;
int main(){

	//create and initialise a vector
	vector<int> a;
	vector<int> b(5,10);//five int with value 10 - can also initilise a vector of zeros (n,0)
	vector<int> c(b.begin(),b.end());
	vector<int> d{1,2,3,10,14};

	//how we can iterate over the vector
	for(int i=0; i<c.size(); i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;

	for(auto it = b.begin(); it!=b.end(); it++){
		cout<<(*it)<<" ";
	}
    cout<<endl;

	//for each loop
	for(int x:d){
		cout<<x<<" ";
	}
	cout<<endl;
// some more functions
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		v.push_back(no);
	}

	for(int x:v){
		cout<<x<<",";
	}
	cout<<endl;	
	//understand at memory level, what are the differences in the two
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl; //size of underlying array
	cout<<v.max_size()<<endl;
 //max no of element a vector can hold in the wrost case acc to avbl memory in system
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl; //size of underlying array
	cout<<d.max_size()<<endl; //max no of element a vector can hold in the wrost case acc to avbl memory in system
}