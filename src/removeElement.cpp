#include<bits/stdc++.h>

using namespace std;

//TODO O(1) space complexity

//O(n) space complexity
int removeElement(vector<int> &A, int B) {
   int temp=0;
   for(int i=0;i<A.size();i++){
       if(A[i]==B){
            A.erase(A.begin()+i);
            i--;
       }
   }
   return A.size();
}


int main(){

	vector<int> A;
	A.push_back(0);
	A.push_back(0);
	A.push_back(2);
	A.push_back(0);
	A.push_back(0);
	A.push_back(0);
	A.push_back(0);
	A.push_back(1);
	A.push_back(0);

	cout<<removeElement(A,2)<<"\n";

	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<"\n";

	return 0;
}