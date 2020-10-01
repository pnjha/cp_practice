#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){

	//you can create and initilise a vector

	vector<int> d{1,2,3,10,14};
	//push back O(1) for most of the time
	d.push_back(16);

	//pop back / remove the last element O(1)
	d.pop_back();

	//insert some elements in the middle
	d.insert(d.begin() + 3,4,100);

	//erase some element in the middle
	d.erase(d.begin()+2);
	d.erase(d.begin()+2,d.begin()+5);

	for(int x:d){
		cout<<x<<",";
	}
	cout<<endl;
	//size
	cout<<"size "<<d.size()<<endl;
	//capacity
	cout<<"capacity "<<d.capacity()<<endl;
	//size increases b'coz of insertion of some elements
	//generally, size does not shrinks

	//we avoid the shrink
	d.resize(8);
	cout<<"size 8 -- "<<d.capacity()<<endl; //does not changes

	d.resize(18);
	cout<<"size 18 -- "<<d.capacity()<<endl;	//changes

	//remove all elements of the vector, does not delete the memory occupied by the array

	d.clear();

	cout<<d.size()<<endl;

	if(d.empty()){
		cout<<"This is an empty vector";
	}


	for(int x:d){
		cout<<x<<",";
	}

	cout<<endl;

	d.push_back(10);
	d.push_back(15);
	d.push_back(12);

	cout<<d.front()<<endl;
	cout<<d.back()<<endl;

	//reserve
	int n;
	cin>>n;
	vector<int> v;

	//To avoid doubling, we use reserve function
	v.reserve(1000);

	for(int i=0; i<n; i++){
		int no;
		cin>>no;
		v.push_back(no);
		cout<<"Changing capacity "<<v.capacity()<<endl;
	}
	cout<<"Capacity "<<v.capacity()<<endl;
	for(int x:v){
		cout<<x<<",";
	}
}