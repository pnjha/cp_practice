#include<iostream>
#include<set>
using namespace std;
int main(){

	set< pair<int,int>> s;
	s.insert(make_pair(10,1));
	s.insert(make_pair(10,5));
	s.insert(make_pair(20,1));
	s.insert(make_pair(20,100));
	s.insert(make_pair(5,1));
	s.insert(make_pair(5,3));
			
	s.erase(s.find(make_pair(5,3)));
	s.insert(make_pair(5,4));

	auto l = s.lower_bound(make_pair(20,1));
	cout<<"Lower bound of 20,1 is "<<l->first<<","<<l->second<<endl;

	auto u = s.upper_bound(make_pair(20,1));
	cout<<"Upper bound of 20,1 is "<<u->first<<","<<u->second<<endl;

	for(auto p:s){
		cout<<p.first<<" and "<<p.second<<endl;
	}
	return 0; 
}	