#include<iostream>
#include"vector.h"
using namespace std;
int main() 
{
	Vector<char> v;

	v.push_back(71);
	cout<<v[0];
	v.push_back(72);
	v.push_back(73);
	v.push_back(74);
	v.push_back(75);
	v.push_back(76);
	v.push_back(77);

	cout<<"Capacity "<<v.capacity()<<endl;

	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}