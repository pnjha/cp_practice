#include<bits/stdc++.h>

using namespace std;

int main(){

	srand((unsigned)time(0));

	double a = 0;
	double b = 1.0*(rand()%1000)/100;
	double c = 1.0*(rand()%1000)/100;
	double d = 1.0*(rand()%1000)/100;
	
	a = 1.0*(b+c+d)/(b*c*d-1);

	cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";

	return 0;
}