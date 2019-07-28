#include<bits/stdc++.h>

using namespace std;

void swap_num(int& a,int& b){
        
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){

	int a = 1, b = 2;
	swap_num(a,b);

	cout<<a<<" "<<b<<"\n";

	return 0;
}