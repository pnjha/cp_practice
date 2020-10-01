//Every pair has uniqe key  

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){

	map<string,int> m;

	//1. Insert
	m.insert(make_pair("Mango", 100));

	//or
	pair<string,int> p;
	p.first = "Apple";
	p.second = 120;

	m.insert(p);

 	//or
 	m["banana"] = 20;

 	//2. Search
 	string fruit;
 	cout<<"Enter the fruit you want to search: "<<endl;
 	cin>>fruit;

 	//update the price
 	m[fruit] += 22;

 	auto it = m.find(fruit);
 	if(it!=m.end()){
 		cout<<"price of "<<fruit<<" is"<<m[fruit]<<endl;
 	}
 	else{
 		cout<<"Fruit is not present."<<endl;
 	}

 	m.erase(fruit);

 	//another way to find a particular map
 	if(m.count(fruit)){
 		cout<<"Price is "<<m[fruit]<<endl;
 	}
 	else{
 		cout<<"Could not find"<<endl;
 	}
 	m["lichi"] = 60;
 	m["pineapple"] = 80;

 	for(auto it=m.begin(); it!=m.end(); it++){
 		cout<<it->first<<" and "<<it->second<<endl;
 	}

 	cout<<endl;

 	//another method
 	for(auto p:m){
 		cout<<p.first<<" : "<<p.second<<endl;
 	}
 	return 0;
}