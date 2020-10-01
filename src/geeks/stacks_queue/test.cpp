#include<bits/stdc++.h>

using namespace std;

int main(){

	vector<int> arr;

	arr.resize(10,0);

	cout<<arr.size()<<"\n";
	cout<<arr.capacity()<<"\n";

	arr.push_back(100);

	cout<<arr.capacity()<<"\n";
	cout<<arr.size()<<"\n";

	arr.resize(5,0);

	cout<<arr.capacity()<<"\n";
	cout<<arr.size()<<"\n";

	arr.clear();
	cout<<arr.capacity()<<"\n";
	cout<<arr.size()<<"\n";

	return 0;
}