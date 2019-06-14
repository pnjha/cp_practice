#include<bits/stdc++.h>

using namespace std;

int missingElement(vector<int> a,vector<int> b){

	int element = 0;

	for(int i = 0;i<a.size();i++)
		element ^= a[i];

	for(int i = 0;i<b.size();i++)
		element ^= b[i];
	
	return element;
}

int main(){

	int a1[] = {1,7,8,5};
	int a2[] = {1,7,5};

	vector<int> a(a1, a1 + sizeof(a1)/sizeof(a1[0]));
	vector<int> b(a2, a2 + sizeof(a2)/sizeof(a2[0]));

	cout<<missingElement(a,b)<<"\n";

	return 0;
}
